//
// Created by cat on 18-11-1.
//

#ifndef PROJECT_COUNTQUERY_H
#define PROJECT_COUNTQUERY_H
#include "../Query.h"
class CountQuery : public ComplexQuery {
    static constexpr const char *qname = "COUNT";
    //Table::ValueType fieldValue;// = (operands[0]=="KEY")? 0 :std::stoi(operands[1]);
    //Table::FieldIndex fieldId;
    // Table::KeyType keyValue;
public:
    std::string getname(){return "COUNT";}
    using ComplexQuery::ComplexQuery;

    QueryResult::Ptr execute() override;

    std::string toString() override;
};
#endif //PROJECT_COUNTQUERY_H
