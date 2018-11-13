//
// Created by liu on 18-10-23.
//

#ifndef PROJECT_DB_H
#define PROJECT_DB_H

#include <memory>
#include <unordered_map>
#include <vector>
#include <utility>
#include <mutex>
#include <thread>

#include "Table.h"
#include "../query/Query.h"
#include "../query/QueryResult.h"
#include "../query/DivQuery.h"

class DivQuery;

class Database {
private:
    /**
     * A unique pointer to the global database object
     */
    static std::unique_ptr<Database> instance;

    std::vector<std::thread> threads;

    int threadnum=8;

    /**
     * The map of tableName -> table unique ptr
     */
    std::unordered_map<std::string, Table::Ptr> tables;

    /**
     * The map of fileName -> tableName
     */
    std::unordered_map<std::string, std::string> fileTableNameMap;

    std::vector<std::unique_ptr<DivQuery> > tasks;
    std::mutex taskMutex;

    std::vector<std::pair<Query::Ptr,QueryResult::Ptr> > results;
    std::mutex resultMutex;

    void runthread(Database *db);

    /**
     * The default constructor is made private for singleton instance
     */
    Database() = default;

public:
    void insertQuery(Query::Ptr &&query);
    void testDuplicate(const std::string &tableName);

    Table &registerTable(Table::Ptr &&table);

    void dropTable(const std::string &tableName);

    void printAllTable();

    Table &operator[](const std::string &tableName);

    const Table &operator[](const std::string &tableName) const;

    Database &operator=(const Database &) = delete;

    Database &operator=(Database &&) = delete;

    Database(const Database &) = delete;

    Database(Database &&) = delete;

    ~Database() = default;

    static Database &getInstance();

    void updateFileTableName(const std::string &fileName, const std::string &tableName);

    std::string getFileTableName(const std::string &fileName);

    /**
     * Load a table from an input stream (i.e., a file)
     * @param is
     * @param source
     * @return reference of loaded table
     */
    Table &loadTableFromStream(std::istream &is, std::string source = "");

    void exit();
};


#endif //PROJECT_DB_H
