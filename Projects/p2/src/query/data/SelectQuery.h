//
// Created by cat on 18-11-1.
//

#ifndef PROJECT_SELECTQUERY_H
#define PROJECT_SELECTQUERY_H

#include "../Query.h"
class SelectQuery : public ComplexQuery {
    static constexpr const char *qname = "SELECT";
    //Table::ValueType fieldValue;// = (operands[0]=="KEY")? 0 :std::stoi(operands[1]);
    //Table::FieldIndex fieldId;
   // Table::KeyType keyValue;
public:
    using ComplexQuery::ComplexQuery;

    QueryResult::Ptr execute() override;

    std::string toString() override;
};
#endif //PROJECT_SELECTQUERY_H
