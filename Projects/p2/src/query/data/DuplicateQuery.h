//
// Created by cat on 18-11-1.
//

#ifndef PROJECT_DUPLICATEQUERY_H
#define PROJECT_DUPLICATEQUERY_H
#include "../Query.h"
class DuplicateQuery : public ComplexQuery {
    static constexpr const char *qname = "DUPLICATE";
    //Table::ValueType fieldValue;// = (operands[0]=="KEY")? 0 :std::stoi(operands[1]);
    //Table::FieldIndex fieldId;
    //Table::KeyType keyValue;
public:
    using ComplexQuery::ComplexQuery;

    QueryResult::Ptr execute() override;

    std::string toString() override;
};

#endif //PROJECT_DUPLICATEQUERY_H
