#ifndef TRUNCATETABLEQUERY_H
#define TRUNCATETABLEQUERY_H
#include "../Query.h"

class TruncateTableQuery : public Query {
    static constexpr const char *qname = "TRUNCATE";
public:
    std::string getname(){return "TRUNCATE";}
    using Query::Query;

    QueryResult::Ptr execute() override;

    std::string toString() override;
};


#endif