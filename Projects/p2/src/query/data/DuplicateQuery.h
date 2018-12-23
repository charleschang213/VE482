//
// Created by cat on 18-11-1.
//

#ifndef PROJECT_DUPLICATEQUERY_H
#define PROJECT_DUPLICATEQUERY_H
#include "../Query.h"
class DuplicateQuery : public ComplexQuery {
    friend class DivQuery;
    static constexpr const char *qname = "DUPLICATE";
    //Table::ValueType fieldValue;// = (operands[0]=="KEY")? 0 :std::stoi(operands[1]);
    //Table::FieldIndex fieldId;
    //Table::KeyType keyValue;
    int counter = 0;
    std::mutex initMutex;
public:
    bool iswrite() override {return true;}
    bool dividable() override {return true;}
    std::string getname() override {return "DUPLICATE";}
    using ComplexQuery::ComplexQuery;

    void combine(int cnt){
        this->glock();
        counter+=cnt;
        this->decgroup();
        if (this->getGroups()==0){
            this->gunlock();
            auto &db = Database::getInstance();
            auto &table = db[this->targetTable];
            table.datacombine();
            //table.insertByIndex(newkey, move(data));
            db.insertResult(this->getId(),std::make_unique<RecordCountResult>(cnt));
        }
        else this->gunlock();
    }

    //QueryResult::Ptr execute() override;

    //std::string toString() override;
};

#endif //PROJECT_DUPLICATEQUERY_H
