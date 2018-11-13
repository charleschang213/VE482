#ifndef DIVQUERY_H
#define DIVQUERY_H
#include "Query.h"
#include "../db/Table.h"
#include "../db/Database.h"
#include "QueryResult.h"

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
        virtual void execute(){}
        int getcounter(){return counter;}
};


#endif