//
// Created by liu on 18-10-25.
//

#ifndef PROJECT_UPDATEQUERY_H
#define PROJECT_UPDATEQUERY_H

#include "../Query.h"

class UpdateQuery : public ComplexQuery {
    friend class DivQuery;
    static constexpr const char *qname = "UPDATE";
    Table::ValueType fieldValue;// = (operands[0]=="KEY")? 0 :std::stoi(operands[1]);
    std::string fieldId;
    Table::KeyType keyValue;
    int counter = 0;
public:
    std::string getname(){return "UPDATE";}
    using ComplexQuery::ComplexQuery;
    void init(){
        auto &db = Database::getInstance();
        if (this->operands[0] == "KEY") {
            this->keyValue = this->operands[1];
        } else {
            this->fieldId = this->operands[0];
            this->fieldValue = (Table::ValueType) strtol(this->operands[1].c_str(), nullptr, 10);
        }
    }
    void combine(int cnt){
        this->counter+=cnt;
        this->decgroup();
        if (this->getGroups()==0){
            auto &db = Database::getInstance();
            db.insertResult(this->getId(),std::make_unique<RecordCountResult>(counter));
        }
    }

    QueryResult::Ptr execute() override;

    std::string toString() override;
};


#endif //PROJECT_UPDATEQUERY_H
