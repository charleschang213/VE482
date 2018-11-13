#ifndef DIVQUERY_H
#define DIVQUERY_H
#include "Query.h"
#include "QueryResult.h"

class Database;

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
        //QueryResult::Ptr UpdateDivExe();

};


#endif