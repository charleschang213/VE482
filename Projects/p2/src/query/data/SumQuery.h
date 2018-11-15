//
//  MaxQuery.h
//
//
//  Created by Sienna on 2018/11/1.
//
//

#ifndef SumQuery_h
#define SumQuery_h

#include "../Query.h"
#include <vector>

class SumQuery : public ComplexQuery {
    friend class DivQuery;
    static constexpr const char *qname = "SUM";
    std::vector<Table::ValueType> FinalSumResult;
    //Table::ValueType fieldValue;// = (operands[0]=="KEY")? 0 :std::stoi(operands[1]);
    //std::string fieldId;
    //Table::KeyType keyValue;
    //int counter = 0;
    //bool initted = false;
    //std::mutex initMutex;
public:
    bool dividable(){return true;}
    std::string getname(){return "SUM";}
    using ComplexQuery::ComplexQuery;

    void combine(std::vector<Table::ValueType> SumResult){
        this->glock();
        //this->counter+=cnt;
        if (FinalSumResult.empty())
            FinalSumResult.insert(FinalSumResult.end(), SumResult.begin(), SumResult.end());
        else {
            for (size_t i=0;i<FinalSumResult.size();i++) FinalSumResult[i]+=SumResult[i];
        }
        this->decgroup();
        if (this->getGroups()==0){
            this->gunlock();
            auto &db = Database::getInstance();
            db.insertResult(this->getId(),std::make_unique<SuccessMsgResultDerv>(FinalSumResult));
        }
        else this->gunlock();
    }

    //QueryResult::Ptr execute() override;

    //std::string toString() override;
};

#endif /* MaxQuery_h */

