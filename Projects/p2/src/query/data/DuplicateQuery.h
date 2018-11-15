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
    std::pair<std::vector<std::string>,std::vector<std::vector<Table::ValueType >>> totalvecter;
    bool initted = false;
    std::mutex initMutex;
public:
    bool iswrite() override {return true;}
    bool dividable() override {return true;}
    std::string getname() override {return "DUPLICATE";}
    using ComplexQuery::ComplexQuery;

    void combine(std::pair<std::vector<std::string>,std::vector<std::vector<Table::ValueType >>> cnt){
        this->glock();
        for(unsigned int i=0;i<cnt.first.size();i++){
            totalvecter.first.push_back(cnt.first[i]);
            totalvecter.second.push_back(cnt.second[i]);
        }
        this->decgroup();
        if (this->getGroups()==0){
            this->gunlock();
            auto &db = Database::getInstance();
            auto &table = db[this->targetTable];
            for(unsigned int i=0;i<totalvecter.first.size();i++){
                table.insertByIndex(totalvecter.first[i],move(totalvecter.second[i]));
            }
            //table.insertByIndex(newkey, move(data));
            db.insertResult(this->getId(),std::make_unique<RecordCountResult>(totalvecter.first.size()));
        }
        else this->gunlock();
    }

    //QueryResult::Ptr execute() override;

    //std::string toString() override;
};

#endif //PROJECT_DUPLICATEQUERY_H
