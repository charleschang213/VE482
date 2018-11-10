//
// Created by liu on 18-10-23.
//

#include "Database.h"
#include "Table.h"

#include <deque>
#include <fstream>
#include <iostream>
#include <iomanip>

std::unique_ptr<Database> Database::instance = nullptr;

void Database::InsertQuery(Query::Ptr &&query) {
    auto qry = query.get();
    ResultMutex.lock();
    qry->setid(results.size());
    results.emplace_back(std::move(qry),nullptr);
    ResultMutex.unlock();
}

void Database::InsertDivQuery(DivQuery* task){
    TaskMutex.lock();
    tasks.push(task);
    TaskMutex.unlock();
}

void Database::InsertResult(Query *query,QueryResult::Ptr result){
    ResultMutex.lock();
    results.at(query->getid()).second = std::move(result);
    ResultMutex.unlock();
}

void Database::DisplayResult(){
    DisplayMutex.lock();
    for (auto it = results.begin()+DoneQuery;it!=results.end()&&it->second!=nullptr;++it){
        std::cout<< it->first->getid();
        it->second->print();
        DoneQuery++;
    }
}

void Database::runthread(Database *db){
    while(true){
        db->TaskMutex.lock();
        if (db->threadlist.empty()){
            db->TaskMutex.unlock();
            if (db->TimeToExit()) return;
            std::this_thread::yield;
        }
        else {
            auto task = db->tasks.front();
            db->tasks.pop();
            db->TaskMutex.unlock();
            task->execute();
        }
    }
}

void Database::testDuplicate(const std::string &tableName) {
    auto it = this->tables.find(tableName);
    if (it != this->tables.end()) {
        throw DuplicatedTableName(
                "Error when inserting table \"" + tableName + "\". Name already exists."
        );
    }
}

Table &Database::registerTable(Table::Ptr &&table) {
    auto name = table->name();
    this->testDuplicate(table->name());
    auto result = this->tables.emplace(name, std::move(table));
    return *(result.first->second);
}


Table &Database::operator[](const std::string &tableName) {
    auto it = this->tables.find(tableName);
    if (it == this->tables.end()) {
        throw TableNameNotFound(
                "Error accesing table \"" + tableName + "\". Table not found."
        );
    }
    return *(it->second);
}

const Table &Database::operator[](const std::string &tableName) const {
    auto it = this->tables.find(tableName);
    if (it == this->tables.end()) {
        throw TableNameNotFound(
                "Error accesing table \"" + tableName + "\". Table not found."
        );
    }
    return *(it->second);
}

void Database::dropTable(const std::string &tableName) {
    auto it = this->tables.find(tableName);
    if (it == this->tables.end()) {
        throw TableNameNotFound(
                "Error when trying to drop table \"" + tableName + "\". Table not found."
        );
    }
    this->tables.erase(it);
}

void Database::printAllTable() {
    const int width = 15;
    std::cout << "Database overview:" << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << std::setw(width) << "Table name";
    std::cout << std::setw(width) << "# of fields";
    std::cout << std::setw(width) << "# of entries" << std::endl;
    for (const auto &table : this->tables) {
        std::cout << std::setw(width) << table.first;
        std::cout << std::setw(width) << (*table.second).field().size() + 1;
        std::cout << std::setw(width) << (*table.second).size() << std::endl;
    }
    std::cout << "Total " << this->tables.size() << " tables." << std::endl;
    std::cout << "=========================" << std::endl;
}

Database &Database::getInstance() {
    if (Database::instance == nullptr) {
        instance = std::unique_ptr<Database>(new Database);
        for (int i=0;i<instance->threadNum;i++){
            instance->threadlist.emplace(instance->threadlist.end(),runthread,instance.get());
        }
    }
    return *instance;
}

void Database::updateFileTableName(const std::string &fileName, const std::string &tableName) {
    fileTableNameMap[fileName] = tableName;
}

std::string Database::getFileTableName(const std::string &fileName) {
    auto it = fileTableNameMap.find(fileName);
    if (it == fileTableNameMap.end()) {
        std::ifstream infile(fileName);
        if (!infile.is_open()) {
            return "";
        }
        std::string tableName;
        infile >> tableName;
        infile.close();
        fileTableNameMap.emplace(fileName, tableName);
        return tableName;
    } else {
        return it->second;
    }
}

Table &Database::loadTableFromStream(std::istream &is, std::string source) {
    auto &db = Database::getInstance();
    std::string errString =
            !source.empty() ?
            R"(Invalid table (from "?") format: )"_f % source :
            "Invalid table format: ";

    std::string tableName;
    Table::SizeType fieldCount;
    std::deque<Table::KeyType> fields;

    std::string line;
    std::stringstream sstream;
    if (!std::getline(is, line))
        throw LoadFromStreamException(
                errString + "Failed to read table metadata line."
        );

    sstream.str(line);
    sstream >> tableName >> fieldCount;
    if (!sstream) {
        throw LoadFromStreamException(
                errString + "Failed to parse table metadata."
        );
    }

    // throw error if tableName duplicates
    db.testDuplicate(tableName);

    if (!(std::getline(is, line))) {
        throw LoadFromStreamException(
                errString + "Failed to load field names."
        );
    }

    sstream.clear();
    sstream.str(line);
    for (Table::SizeType i = 0; i < fieldCount; ++i) {
        std::string field;
        if (!(sstream >> field)) {
            throw LoadFromStreamException(
                    errString + "Failed to load field names."
            );
        }
        else {
            fields.emplace_back(std::move(field));
        }
    }

    if (fields.front() != "KEY") {
        throw LoadFromStreamException(
                errString + "Missing or invalid KEY field."
        );
    }

    fields.erase(fields.begin()); // Remove leading key
    auto table = std::make_unique<Table>(tableName, fields);

    Table::SizeType lineCount = 2;
    while (std::getline(is, line)) {
        if (line.empty()) break; // Read to an empty line
        lineCount++;
        sstream.clear();
        sstream.str(line);
        std::string key;
        if (!(sstream >> key))
            throw LoadFromStreamException(
                    errString + "Missing or invalid KEY field."
            );
        std::vector<Table::ValueType> tuple;
        tuple.reserve(fieldCount - 1);
        for (Table::SizeType i = 1; i < fieldCount; ++i) {
            Table::ValueType value;
            if (!(sstream >> value))
                throw LoadFromStreamException(
                        errString + "Invalid row on LINE " + std::to_string(lineCount)
                );
            tuple.emplace_back(value);
        }
        table->insertByIndex(key, std::move(tuple));
    }

    return db.registerTable(std::move(table));
}

void Database::exit() {
    // We are being lazy here ...
    // Might cause problem ...
    std::exit(0);
}
