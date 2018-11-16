//
// Created by liu on 18-10-23.
//

#include "Database.h"
#include "Table.h"
#include "../query/Query.h"

#include <deque>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

std::unique_ptr<Database> Database::instance = nullptr;

void Database::testDuplicate(const std::string &tableName)
{
    auto it = this->tables.find(tableName);
    if (it != this->tables.end())
    {
        throw DuplicatedTableName(
            "Error when inserting table \"" + tableName + "\". Name already exists.");
    }
}

void Database::insertQuery(std::unique_ptr<Query> &&query, std::unique_ptr<QueryResult> &&result)
{
    auto q = query.get();
    resultMutex.lock();
    q->setId(results.size());
    results.emplace_back(std::move(query), std::move(result));
    for (unsigned int i = resultflag; i < this->results.size() && results[i].second != nullptr; i++)
    {
        if (results[i].first->getname() != "QUIT")
            std::cout << i + 1 << std::endl;
        std::cout << *(this->results[i].second);
        if (i>130) std::cerr << i+1 << std::endl;
        std::cout.flush();
        resultflag++;
    }
    resultMutex.unlock();
}
void Database::insertQuery(std::unique_ptr<Query> &&query)
{
    if (query->uniquery())
    {
        auto q = query.get();
        int id = -1;
        resultMutex.lock();
        q->setId(results.size());
        id = q->getId();
        results.emplace_back(std::move(query), nullptr);
        resultMutex.unlock();
        taskMutex.lock();
        tasks.push_back(DivQuery(id, "", 0));
        //std::cout << "Added" << std::endl;
        taskMutex.unlock();
        return;
    }
    if (!query->iscreate())
    {
        auto q = query.get();
        while (true)
        {
            bool a = false;
            std::string tablename = query->getTableName();
            waitingMutex.lock();
            a = (std::count(waiting.begin(), waiting.end(), tablename)) == 0;
            waitingMutex.unlock();
            try
            {
                (*this)[tablename];
            }
            catch (const TableNameNotFound &e)
            {
                a = false;
            }
            if (a)
                break;
        }
        auto &table = (*this)[query->getTableName()];
        int groups = 0;
        int size = 0;
        int id = -1;
        bool dividable = query->dividable();
        std::string tablename = query->getTableName();
        //std::cout << "Adding" << std::endl;
        resultMutex.lock();
        query->setId(results.size());
        id = query->getId();
        results.emplace_back(std::move(query), nullptr);
        resultMutex.unlock();
        if (dividable)
        {
            while (true)
            {
                bool jo = false;
                table.tlock();
                if (table.getstatus() >= 0)
                {
                    jo = true;
                    size = table.size();
                }
                table.tunlock();
                if (jo == true)
                    break;
            }
            groups = size / Partnumber + 1;
            taskMutex.lock();
            for (int i = 0; i < groups; i++)
            {
                tasks.push_back(DivQuery(id, tablename, i));
            }
            taskMutex.unlock();
            resultMutex.lock();
            results[id].first->setGroups(groups);
            resultMutex.unlock();
        }
        else
        {
            taskMutex.lock();
            tasks.push_back(DivQuery(id, tablename, 0));
            taskMutex.unlock();
        }
    }
    else
    {
        auto q = query.get();
        std::string tablename = q->getTableName();
        resultMutex.lock();
        q->setId(results.size());
        int id = -1;
        id = q->getId();
        results.emplace_back(std::move(query), nullptr);
        resultMutex.unlock();
        taskMutex.lock();
        tasks.push_back(DivQuery(id, tablename, 0));
        taskMutex.unlock();
        waitingMutex.lock();
        waiting.push_back(q->getTableName());
        waitingMutex.unlock();
    }
}

void Database::insertResult(int id, QueryResult::Ptr result)
{
    resultMutex.lock();
    this->results[id].second = std::move(result);
    for (unsigned int i = resultflag; i < this->results.size() && results[i].second != nullptr; i++)
    {
        if (results[i].first->getname() != "QUIT")
            std::cout << i + 1 << std::endl;
        std::cout << *(this->results[i].second);
        if (i>90) std::cerr << i+1 << std::endl;
        std::cout.flush();
        resultflag++;
    }
    resultMutex.unlock();
}

bool Database::TableExists(const std::string &tablename)
{
    auto it = this->tables.find(tablename);
    return it != this->tables.end();
}

void Database::runthread(Database *db)
{
    //std::cout << "Hi" << std::endl;
    while (true)
    {
        db->taskMutex.lock();
        if (db->taskcursor == db->tasks.size())
        {
            db->taskMutex.unlock();
            if (db->ExitTime())
                return;
            std::this_thread::yield();
        }
        else
        {
            auto &task = db->tasks[db->taskcursor];
            int id = task.getid();
            //auto &query = db->results[task.getid()].first;
            std::string name = db->results[task.getid()].first->getTableName();
            std::string qname = db->results[id].first->getname();
            bool qiscreate = db->results[id].first->iscreate();
            bool qdividable = db->results[id].first->dividable();
            bool qunique = db->results[id].first->uniquery();
            bool qiswrite = db->results[id].first->iswrite();
            std::string oldname = db->results[id].first->oldtable();
            db->taskcursor++;
            db->taskMutex.unlock();
            //std::cout << "Getit" << std::endl;
            try
            {

                if (qname == "DROP" || qname == "COPYTABLE" || qname == "DUMP")
                {
                    while (true)
                    {
                        //std::cerr << db->getresultflag() << " " << id << std::endl;
                        if (db->getresultflag() >= id)
                            break;
                    }
                }
                if (qiscreate || qunique)
                {
                    db->results[id].first->execute();
                    db->insertResult(id, std::make_unique<NullQueryResult>());
                    //std::cout << "Done" << std::endl;
                    db->deletewaiting(name);
                    continue;
                }
                //std::cout << "Wait for table Creation" << std::endl;
                while (true)
                {
                    int a = 0;
                    db->waitingMutex.lock();
                    a = std::count(db->waiting.begin(), db->waiting.end(), name);
                    db->waitingMutex.unlock();
                    if (a == 0)
                        break;
                }
                //std::cout << "Founded" << std::endl;
                if (qname == "DUMP")
                {
                    std::cerr << "Begin Waiting " << id << std::endl;
                    while (true)
                    {
                        bool a = true;
                        try
                        {
                            (*db)[name];
                        }
                        catch (const TableNameNotFound &e)
                        {
                            a = false;
                        }
                        if (a)
                            break;
                    }
                    std::cerr << "End Waiting " << id << std::endl;
                }
                auto &table = (*db)[name];
                //std::cout << "Wait for table operations" << std::endl;
                while (true)
                {
                    bool a = false;
                    table.tlock();
                    //std::cout << query->getId() << " " << table.getstatus() << std::endl;
                    if (table.getstatus() < 0)
                    {
                        if (table.getstatus() + id == 0)
                        {
                            a = true;
                            table.upactive();
                        }
                    }
                    else if (table.getstatus() == 0)
                    {
                        a = true;
                        if (qiswrite)
                        {
                            table.setstatus(0 - id);
                            table.upactive();
                        }
                        else
                        {
                            table.setstatus(id);
                            table.upactive();
                        }
                    }
                    else
                    {
                        if (!qiswrite)
                        {
                            a = true;
                            table.upactive();
                        }
                    }
                    table.tunlock();
                    if (a)
                        break;
                }
                //std::cout << "work" << std::endl;
                if (qdividable)
                    task.execute();
                else
                {
                    if (qname == "DROP")
                    {
                        table.tlock();
                        db->results[id].first->execute();
                        db->insertResult(id, std::make_unique<NullQueryResult>());
                    }
                    else
                    {
                        if (qname == "COPYTABLE")
                        {
                            (*db)[oldname].tlock();
                        }
                        db->results[id].first->execute();
                        db->insertResult(id, std::make_unique<NullQueryResult>());
                    }
                }
                //db->deletewaiting(query->getTableName());
                if (qname != "DROP")
                {
                    table.tlock();
                    table.downactive();
                    if ((table.getactive() == 0) && (((table.getstatus() >= 0)) || (db->results[id].first->getGroups() == 0)))
                        table.setstatus(0);
                    table.tunlock();
                    if (qname == "COPYTABLE")
                    {
                        (*db)[oldname].tunlock();
                    }
                }
            }
            catch (const TableNameNotFound &e)
            {
                std::cerr << "tablenotfound" << id << std::endl;
            }
        }
    }
}

Table &Database::registerTable(Table::Ptr &&table)
{
    auto name = table->name();
    this->testDuplicate(table->name());
    auto result = this->tables.emplace(name, std::move(table));
    return *(result.first->second);
}

Table &Database::operator[](const std::string &tableName)
{
    if (this->tables.empty())
    {
        throw TableNameNotFound(
            "Error accesing table \"" + tableName + "\". Table not found.");
    }
    auto it = this->tables.find(tableName);
    if (it == this->tables.end())
    {
        throw TableNameNotFound(
            "Error accesing table \"" + tableName + "\". Table not found.");
    }
    return *(it->second);
}

const Table &Database::operator[](const std::string &tableName) const
{
    auto it = this->tables.find(tableName);
    if (it == this->tables.end())
    {
        throw TableNameNotFound(
            "Error accesing table \"" + tableName + "\". Table not found.");
    }
    return *(it->second);
}

void Database::dropTable(const std::string &tableName)
{
    auto it = this->tables.find(tableName);
    if (it == this->tables.end())
    {
        throw TableNameNotFound(
            "Error when trying to drop table \"" + tableName + "\". Table not found.");
    }
    this->tables.erase(it);
}

void Database::printAllTable()
{
    const int width = 15;
    std::cout << "Database overview:" << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << std::setw(width) << "Table name";
    std::cout << std::setw(width) << "# of fields";
    std::cout << std::setw(width) << "# of entries" << std::endl;
    for (const auto &table : this->tables)
    {
        std::cout << std::setw(width) << table.first;
        std::cout << std::setw(width) << (*table.second).field().size() + 1;
        std::cout << std::setw(width) << (*table.second).size() << std::endl;
    }
    std::cout << "Total " << this->tables.size() << " tables." << std::endl;
    std::cout << "=========================" << std::endl;
}

Database &Database::getInstance(int threads)
{
    if (Database::instance == nullptr)
    {
        instance = std::unique_ptr<Database>(new Database);
        if (threads == 0)
            instance->threadnum = std::thread::hardware_concurrency();
        else
            instance->threadnum = threads;
        std::cerr << "Thread Number " << instance->threadnum << std::endl;
        instance->tasks.reserve(100000);
        for (int i = 0; i < instance->threadnum; i++)
            instance->threads.emplace_back(runthread, instance.get());
    }
    return *instance;
}

void Database::updateFileTableName(const std::string &fileName, const std::string &tableName)
{
    fileTableNameMap[fileName] = tableName;
}

std::string Database::getFileTableName(const std::string &fileName)
{
    auto it = fileTableNameMap.find(fileName);
    if (it == fileTableNameMap.end())
    {
        std::ifstream infile(fileName);
        if (!infile.is_open())
        {
            return "";
        }
        std::string tableName;
        infile >> tableName;
        infile.close();
        fileTableNameMap.emplace(fileName, tableName);
        return tableName;
    }
    else
    {
        return it->second;
    }
}

Table &Database::loadTableFromStream(std::istream &is, std::string source)
{
    auto &db = Database::getInstance();
    std::string errString =
        !source.empty() ?
                        R"(Invalid table (from "?") format: )"_f % source
                        : "Invalid table format: ";

    std::string tableName;
    Table::SizeType fieldCount;
    std::deque<Table::KeyType> fields;

    std::string line;
    std::stringstream sstream;
    if (!std::getline(is, line))
        throw LoadFromStreamException(
            errString + "Failed to read table metadata line.");

    sstream.str(line);
    sstream >> tableName >> fieldCount;
    if (!sstream)
    {
        throw LoadFromStreamException(
            errString + "Failed to parse table metadata.");
    }

    // throw error if tableName duplicates
    db.testDuplicate(tableName);

    if (!(std::getline(is, line)))
    {
        throw LoadFromStreamException(
            errString + "Failed to load field names.");
    }

    sstream.clear();
    sstream.str(line);
    for (Table::SizeType i = 0; i < fieldCount; ++i)
    {
        std::string field;
        if (!(sstream >> field))
        {
            throw LoadFromStreamException(
                errString + "Failed to load field names.");
        }
        else
        {
            fields.emplace_back(std::move(field));
        }
    }

    if (fields.front() != "KEY")
    {
        throw LoadFromStreamException(
            errString + "Missing or invalid KEY field.");
    }

    fields.erase(fields.begin()); // Remove leading key
    auto table = std::make_unique<Table>(tableName, fields);

    Table::SizeType lineCount = 2;
    while (std::getline(is, line))
    {
        if (line.empty())
            break; // Read to an empty line
        lineCount++;
        sstream.clear();
        sstream.str(line);
        std::string key;
        if (!(sstream >> key))
            throw LoadFromStreamException(
                errString + "Missing or invalid KEY field.");
        std::vector<Table::ValueType> tuple;
        tuple.reserve(fieldCount - 1);
        for (Table::SizeType i = 1; i < fieldCount; ++i)
        {
            Table::ValueType value;
            if (!(sstream >> value))
                throw LoadFromStreamException(
                    errString + "Invalid row on LINE " + std::to_string(lineCount));
            tuple.emplace_back(value);
        }
        table->insertByIndex(key, std::move(tuple));
    }

    return db.registerTable(std::move(table));
}

void Database::exit()
{
    // We are being lazy here ...
    // Might cause problem ...
    std::exit(0);
}
