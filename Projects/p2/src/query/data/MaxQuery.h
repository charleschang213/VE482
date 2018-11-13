//
//  MaxQuery.h
//  
//
//  Created by Sienna on 2018/11/1.
//
//

#ifndef MaxQuery_h
#define MaxQuery_h

#include "../Query.h"

class MaxQuery : public ComplexQuery {
    static constexpr const char *qname = "MAX";
    //Table::ValueType fieldValue;// = (operands[0]=="KEY")? 0 :std::stoi(operands[1]);
    //Table::FieldIndex fieldId;
    //Table::KeyType keyValue;
public:
    std::string getname(){return "MAX";}
    using ComplexQuery::ComplexQuery;
    
    QueryResult::Ptr execute() override;
    
    std::string toString() override;
};

#endif /* MaxQuery_h */

