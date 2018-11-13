//
// Created by liu on 18-10-25.
//

#ifndef PROJECT_INSERTQUERY_H
#define PROJECT_INSERTQUERY_H

#include "../Query.h"

class InsertQuery : public ComplexQuery {
    static constexpr const char *qname = "INSERT";
public:
    bool dividable(){return false;}
    std::string getname(){return "INSERT";}
    using ComplexQuery::ComplexQuery;

    QueryResult::Ptr execute() override;

    std::string toString() override;
};


#endif //PROJECT_INSERTQUERY_H
