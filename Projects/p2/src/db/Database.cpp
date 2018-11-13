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

void Database::testDuplicate(const std::string &tableName) {
    auto it = this->tables.find(tableName);
    if (it != this->tables.end()) {
        throw DuplicatedTableName(
                "Error when inserting table \"" + tableName + "\". Name already exists."
        );
    }
}

void Database::insertQuery(Query::Ptr &&query){
    auto q = query.get();
    auto &table = (*this)[q->getTableName()];
    int groups=0;
    int size=0;
    int id=-1;
    bool dividable = q->dividable();
    std::string tablename = q->getTableName();
    resultMutex.lock();
    q->setId(results.size());
    id = q->getId();
    results.emplace_back(std::move(query),nullptr);
    results.back().first->setGroups(groups);
    resultMutex.unlock();
    while (true){
        bool jo = false;
        table.tlock();
        if (table.getstatus()>=0) {
            jo=true;
            size = table.size();
        }
        table.tunlock();
        if (jo==true) break;
    }
    if (dividable){
        groups = size/100+1;
        taskMutex.lock();
        for (int i=0;i<groups;i++){
            tasks.emplace_back(std::make_unique<DivQuery>(id,tablename,i));
        }
        taskMutex.unlock();
    }
    else {
        taskMutex.lock();
        tasks.emplace_back(std::make_unique<DivQuery>(id,tablename,0));
    }
}

void Database::runthread(Database *db){

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
        for (int i=0;i<threadnum;i++)
            threads.emplace_back(runthread,instance.get());
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
