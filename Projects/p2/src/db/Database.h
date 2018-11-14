//
// Created by liu on 18-10-23.
//

#ifndef PROJECT_DB_H
#define PROJECT_DB_H

#include <memory>
#include <unordered_map>
#include <vector>
#include <utility>
#include <queue>
#include <mutex>
#include <thread>


#include "../query/Query.h"
//#include "../query/DivQuery.h"

#include "Table.h"
#include "../query/QueryResult.h"

class DivQuery;

class Query;

class Database {
private:
    /**
     * A unique pointer to the global database object
     */
    static std::unique_ptr<Database> instance;

    std::vector<std::thread> threads;

    int threadnum=8;

    bool timetoexit = false;

    /**
     * The map of tableName -> table unique ptr
     */
    std::unordered_map<std::string, std::unique_ptr<Table> > tables;

    /**
     * The map of fileName -> tableName
     */
    std::unordered_map<std::string, std::string> fileTableNameMap;

    std::queue<DivQuery> tasks;
    std::mutex taskMutex;

    std::vector<std::pair<std::unique_ptr<Query>,std::unique_ptr<QueryResult> > > results;
    std::mutex resultMutex;

    static void runthread(Database *db);

    /**
     * The default constructor is made private for singleton instance
     */
    Database() = default;
    
    std::vector<std::string> waiting;
    std::mutex waitingMutex;

public:
    friend class DivQuery; 
    void jointhread(){
        for (auto &thread : threads)
            thread.join();
    }
    void insertQuery(std::unique_ptr<Query> &&query);
    void testDuplicate(const std::string &tableName);
    void setExit(){timetoexit=true;}
    bool ExitTime(){return timetoexit;}
    void deletewaiting(std::string tablename){
        waitingMutex.lock();
        for (auto it=waiting.begin();it<waiting.end();it++){
            if (*it==tablename){
                waiting.erase(it);
                break;
            }
        }
        waitingMutex.unlock();
    }
    Table &registerTable(Table::Ptr &&table);
    std::string getqueryname(int id){return results[id].first->getname();}

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

static const int Partnumber = 100;

class DivQuery{
    private:
        int id;
        std::string target;
        int counter;
        QueryResult::Ptr result = nullptr;
    public:
        friend class Database;
        typedef std::unique_ptr<DivQuery> Ptr;
        DivQuery(int id,std::string target,int counter):id(id),target(target),counter(counter){}
        ~DivQuery()=default;
        void execute(){
            auto &db = Database::getInstance();
            std::string name = db.getqueryname(id);
            if (name=="LOAD"){
                result = NullDivExe();
            }else if (name=="DUMP"){
                result = NullDivExe();
            }else if (name=="TRUNCATE"){
                result = NullDivExe();
            }else if (name=="COPYTABLE"){
                result = NullDivExe();
            }else if (name=="DROP"){
                result = NullDivExe();
            }else if (name=="LIST"){
                result = NullDivExe();
            }else if (name=="PRINT"){
                result = NullDivExe();
            }else if (name=="QUIT"){
                result = NullDivExe();
            }else if (name=="ADD"){
                result = NullDivExe();
            }else if (name=="COUNT"){
                result = NullDivExe();
            }else if (name=="DELETE"){
                result = NullDivExe();
            }else if (name=="DUPLICATE"){
                result = NullDivExe();
            }else if (name=="INSERT"){
                result = NullDivExe();
            }else if (name=="MAX"){
                result = NullDivExe();
            }else if (name=="MIN"){
                result = NullDivExe();
            }else if (name=="SELECT"){
                result = NullDivExe();
            }else if (name=="SUB"){
                result = NullDivExe();
            }else if (name=="SUM"){
                result = NullDivExe();
            }else if (name=="SWAP"){
                result = NullDivExe();
            }else if (name=="UPDATE"){
                result = NullDivExe();
            }
        }
        int getcounter(){return counter;}
        int getid(){return id;}
        QueryResult::Ptr NullDivExe(){return std::make_unique<NullQueryResult>();}
        //QueryResult::Ptr LoadDivExe();
        //QueryResult::Ptr DumpDivExe();
        //QueryResult::Ptr TruncateDivExe();
        //QueryResult::Ptr DropDivExe();
        //QueryResult::Ptr CopytableDivExe();
        //QueryResult::Ptr AddDivExe();
        //QueryResult::Ptr ListDivExe();
        //QueryResult::Ptr PrintDivExe();
        //QueryResult::Ptr QuitDivExe();
        //QueryResult::Ptr AddDivExe();
        //QueryResult::Ptr CountDivExe();
        //QueryResult::Ptr DeleteDivExe();
        //QueryResult::Ptr DuplicateDivExe();
        //QueryResult::Ptr InsertDivExe();
        //QueryResult::Ptr MaxDivExe();
        //QueryResult::Ptr MinDivExe();
        //QueryResult::Ptr SelectDivExe();
        //QueryResult::Ptr LubDivExe();
        //QueryResult::Ptr SumDivExe();
        //QueryResult::Ptr SwapDivExe();
        QueryResult::Ptr UpdateDivExe();

};



#endif //PROJECT_DB_H
