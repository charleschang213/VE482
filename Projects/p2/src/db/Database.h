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

    unsigned int resultflag = 0;

    bool timetoexit = false;

    /**
     * The map of tableName -> table unique ptr
     */
    std::unordered_map<std::string, std::unique_ptr<Table> > tables;

    /**
     * The map of fileName -> tableName
     */
    std::unordered_map<std::string, std::string> fileTableNameMap;

    std::vector<DivQuery> tasks;
    unsigned long taskcursor = 0;
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
    int getresultflag(){
        resultMutex.lock();
        int rf = resultflag;
        resultMutex.unlock();
        return rf;
    }
    void insertResult(int id,QueryResult::Ptr result);
    void insertQuery(std::unique_ptr<Query> &&query);
    void insertQuery(std::unique_ptr<Query> &&query,std::unique_ptr<QueryResult> &&result);
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

    bool TableExists(const std::string &tablename);

    const Table &operator[](const std::string &tableName) const;

    Database &operator=(const Database &) = delete;

    Database &operator=(Database &&) = delete;

    Database(const Database &) = delete;

    Database(Database &&) = delete;

    ~Database() = default;

    static Database &getInstance(int threads=0);

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

static const int Partnumber = 100000;

class DivQuery{
    private:
        int id;
        std::string target;
        int counter;
    public:
        friend class Database;
        typedef std::unique_ptr<DivQuery> Ptr;
        DivQuery(int id,std::string target,int counter):id(id),target(target),counter(counter){}
        ~DivQuery()=default;
        void execute(){
            auto &db = Database::getInstance();
            std::string name = db.getqueryname(id);
            if (name=="LOAD"){
                NullDivExe();
            }else if (name=="DUMP"){
                NullDivExe();
            }else if (name=="TRUNCATE"){
                NullDivExe();
            }else if (name=="COPYTABLE"){
                NullDivExe();
            }else if (name=="DROP"){
                NullDivExe();
            }else if (name=="LIST"){
                NullDivExe();
            }else if (name=="PRINT"){
                NullDivExe();
            }else if (name=="QUIT"){
                NullDivExe();
            }else if (name=="ADD"){
                AddDivExe();
            }else if (name=="COUNT"){
                CountDivExe();
            }else if (name=="DELETE"){
                DeleteDivExe();
            }else if (name=="DUPLICATE"){
                DuplicateDivExe();
            }else if (name=="INSERT"){
                NullDivExe();
            }else if (name=="MAX"){
                MaxDivExe();
            }else if (name=="MIN"){
                MinDivExe();
            }else if (name=="SELECT"){
                SelectDivExe();
            }else if (name=="SUB"){
                SubDivExe();
            }else if (name=="SUM"){
                SumDivExe();
            }else if (name=="SWAP"){
                SwapDivExe();
            }else if (name=="UPDATE"){
                UpdateDivExe();
            }else{
                NullDivExe();
            }
        }
        int getcounter(){return counter;}
        int getid(){return id;}
        void NullDivExe(){}
        //void LoadDivExe();
        //void DumpDivExe();
        //void TruncateDivExe();
        //void DropDivExe();
        //void CopytableDivExe();
        //void ListDivExe();
        //void PrintDivExe();
        //void QuitDivExe();
        void AddDivExe();
        void CountDivExe();
        void DeleteDivExe();
        void DuplicateDivExe();
        //void InsertDivExe();
        void MaxDivExe();
        void MinDivExe();
        void SelectDivExe();
        void SubDivExe();
        void SumDivExe();
        void SwapDivExe();
        void UpdateDivExe();

};



#endif //PROJECT_DB_H
