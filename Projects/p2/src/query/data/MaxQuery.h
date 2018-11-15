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
#include <vector>

class MaxQuery : public ComplexQuery {
    friend class DivQuery;
    static constexpr const char *qname = "MAX";
    std::vector<Table::ValueType> FinalMaximum;
    //Table::ValueType fieldValue;// = (operands[0]=="KEY")? 0 :std::stoi(operands[1]);
    //std::string fieldId;
    //Table::KeyType keyValue;
    //int counter = 0;
    //bool initted = false;
    //std::mutex initMutex;
public:
    bool dividable(){return true;}
    std::string getname(){return "MAX";}
    using ComplexQuery::ComplexQuery;

    void combine(std::vector<Table::ValueType> Maximum){
        this->glock();
        //this->counter+=cnt;
        if (FinalMaximum.empty())
            FinalMaximum.insert(FinalMaximum.end(), Maximum.begin(), Maximum.end());
        else {
            for (size_t i=0;i<Maximum.size();i++)
            if (Maximum[i]>FinalMaximum[i]) FinalMaximum[i] = Maximum[i];
        }
        this->decgroup();
        if (this->getGroups()==0){
            this->gunlock();
            auto &db = Database::getInstance();
            db.insertResult(this->getId(),std::make_unique<SuccessMsgResultDerv>(FinalMaximum));
        }
        else this->gunlock();
    }

    QueryResult::Ptr execute() override;

    std::string toString() override;
};

#endif /* MaxQuery_h */

