#ifndef COPYTABLEQUERY_H
#define COPYTABLEQUERY_H
#include "../Query.h"
#include "../DivQuery.h"

class CopyTableQuery : public DividableQuery {
    static constexpr const char *qname = "COPYTABLE";
    const std::string NewTable;
public:
    explicit CopyTableQuery(std::string table, std::string NewTable) :
            DividableQuery(std::move(table)), NewTable(std::move(NewTable)) {}
    bool Dividable(){return false;}

    QueryResult::Ptr execute() override;

    std::string toString() override;

};

#endif