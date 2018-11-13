#ifndef DIVQUERY_H
#define DIVQUERY_H
#include "Query.h"
#include "../db/Table.h"
#include "../db/Database.h"
#include "QueryResult.h"

class DivQuery{
    private:
        Query *query;
        Table *target;
        int counter;
    public:
        friend class Database;
        typedef std::unique_ptr<DivQuery> Ptr;
        DivQuery(Query *query,Table *target,int counter):query(query),target(target),counter(counter){}
        ~DivQuery()=default;
        virtual void execute(){}
        int getcounter(){return counter;}
};


#endif