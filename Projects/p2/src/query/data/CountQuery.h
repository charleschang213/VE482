//
// Created by cat on 18-11-1.
//

#ifndef PROJECT_COUNTQUERY_H
#define PROJECT_COUNTQUERY_H
#include "../Query.h"
class CountQuery : public ComplexQuery {
    friend class DivQuery;
    static constexpr const char *qname = "COUNT";
    //Table::ValueType fieldValue;// = (operands[0]=="KEY")? 0 :std::stoi(operands[1]);
    //Table::FieldIndex fieldId;
    // Table::KeyType keyValue;
    int counter=0;
    bool initted = false;
    std::mutex initMutex;
public:
    bool iswrite() override {return false;}
    bool dividable() override {return true;}
    std::string getname() override {return "COUNT";}
    using ComplexQuery::ComplexQuery;
    void combine(int cnt){
        this->glock();
        this->counter+=cnt;
        this->decgroup();
        if (this->getGroups()==0){
            this->gunlock();
            auto &db = Database::getInstance();
            db.insertResult(this->getId(),std::make_unique<SuccessMsgResult>(counter));
        }
        else this->gunlock();
    }
    //QueryResult::Ptr execute() override;

    //std::string toString() override;
};
#endif //PROJECT_COUNTQUERY_H
