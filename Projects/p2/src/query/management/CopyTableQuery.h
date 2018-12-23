#ifndef COPYTABLEQUERY_H
#define COPYTABLEQUERY_H
#include "../Query.h"

class CopyTableQuery : public Query {
    static constexpr const char *qname = "COPYTABLE";
    const std::string NewTable;
public:
    std::string oldtable() override {return NewTable;}
    bool iscreate() override {return true;}
    std::string getname() override {return "COPYTABLE";}
    explicit CopyTableQuery(std::string table, std::string NewTable) :
            Query(std::move(NewTable)), NewTable(std::move(table)) {}

    QueryResult::Ptr execute() override;

    std::string toString() override;

};

#endif