//
//  MaxQuery.h
//
//
//  Created by Sienna on 2018/11/1.
//
//

#ifndef MinQuery_h
#define MinQuery_h

#include "../Query.h"
#include <vector>

class MinQuery : public ComplexQuery {
    friend class DivQuery;
    static constexpr const char *qname = "MIN";
    std::vector<Table::ValueType> FinalMinimum;
    //Table::ValueType fieldValue;// = (operands[0]=="KEY")? 0 :std::stoi(operands[1]);
    //std::string fieldId;
    //Table::KeyType keyValue;
    //int counter = 0;
    //bool initted = false;
    //std::mutex initMutex;
public:
    bool dividable(){return true;}
    std::string getname(){return "MIN";}
    using ComplexQuery::ComplexQuery;

    void combine(std::vector<Table::ValueType> Minimum){
        this->glock();
        //this->counter+=cnt;
        FinalMinimum.insert(FinalMinimum.end(), Minimum.begin(), Minimum.end());
        this->decgroup();
        if (this->getGroups()==0){
            this->gunlock();
            auto &db = Database::getInstance();
            db.insertResult(this->getId(),std::make_unique<SuccessMsgResultDerv>(FinalMinimum));
        }
        else this->gunlock();
    }

    QueryResult::Ptr execute() override;

    std::string toString() override;
};

#endif /* MaxQuery_h */

