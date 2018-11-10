//
// Created by liu on 18-10-23.
//

#ifndef PROJECT_DB_H
#define PROJECT_DB_H

#include <memory>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <queue>

#include "Table.h"
#include "../query/Query.h"
#include "../query/DivQuery.h"

class Query;
class DivQuery;

class Database {
private:
    /**
     * A unique pointer to the global database object
     */
    static std::unique_ptr<Database> instance;

    /**
     * The map of tableName -> table unique ptr
     */
    std::unordered_map<std::string, Table::Ptr> tables;

    /**
     * The map of fileName -> tableName
     */
    std::unordered_map<std::string, std::string> fileTableNameMap;

    /**
     * The default constructor is made private for singleton instance
     */
    
    Database() = default;

    std::mutex ResultMutex;
    std::vector<std::pair<Query::Ptr,QueryResult::Ptr> > results;

    std::queue<DivQuery*> tasks;
    std::mutex TaskMutex;

    std::mutex DisplayMutex;

    std::vector<std::thread> threadlist;
    static void runthread(Database *db);
    int DoneQuery = 0;
    bool nowexit = false;
    int threadNum=8;


public:
    bool TimeToExit(){return nowexit;}

    bool SetExit(){nowexit = true;}

    void InsertQuery(Query::Ptr &&query);

    void InsertDivQuery(DivQuery* task);

    void InsertResult(Query *query,QueryResult::Ptr result);

    void DisplayResult();
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
