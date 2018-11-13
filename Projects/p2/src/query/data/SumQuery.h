//
//  SumQuery.h
//  
//
//  Created by Sienna on 2018/11/1.
//
//

#ifndef SumQuery_h
#define SumQuery_h

#include "../Query.h"

class SumQuery : public ComplexQuery {
    static constexpr const char *qname = "SUM";
    //Table::ValueType fieldValue;// = (operands[0]=="KEY")? 0 :std::stoi(operands[1]);
    //Table::FieldIndex fieldId;
    //Table::KeyType keyValue;
public:
    std::string getname(){return "SUM";}
    using ComplexQuery::ComplexQuery;
    
    QueryResult::Ptr execute() override;
    
    std::string toString() override;
};

#endif /* SumQuery_h */

