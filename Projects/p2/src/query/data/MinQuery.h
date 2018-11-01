//
//  MinQuery.h
//  
//
//  Created by Sienna on 2018/11/1.
//
//

#ifndef MinQuery_h
#define MinQuery_h

#include "../Query.h"

class MinQuery : public ComplexQuery {
    static constexpr const char *qname = "MIN";
    Table::ValueType fieldValue;// = (operands[0]=="KEY")? 0 :std::stoi(operands[1]);
    Table::FieldIndex fieldId;
    Table::KeyType keyValue;
public:
    using ComplexQuery::ComplexQuery;
    
    QueryResult::Ptr execute() override;
    
    std::string toString() override;
};

#endif /* MinQuery_h */

