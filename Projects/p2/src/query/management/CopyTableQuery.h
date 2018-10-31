#ifndef COPYTABLEQUERY_H
#define COPYTABLEQUERY_H
#include "../Query.h"

class CopyTableQuery : public Query {
    static constexpr const char *qname = "COPYTABLE";
    const std::string NewTable;
public:
    explicit CopyTableQuery(std::string table, std::string NewTable) :
            Query(std::move(table)), NewTable(std::move(NewTable)) {}

    QueryResult::Ptr execute() override;

    std::string toString() override;

};

#endif