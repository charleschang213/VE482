//
// Created by cat on 18-11-1.
//

#ifndef PROJECT_SELECTQUERY_H
#define PROJECT_SELECTQUERY_H

#include "../Query.h"
class SelectQuery : public ComplexQuery {
    static constexpr const char *qname = "SELECT";
    //Table::ValueType fieldValue;// = (operands[0]=="KEY")? 0 :std::stoi(operands[1]);
    //Table::FieldIndex fieldId;
   // Table::KeyType keyValue;
    std::pair<std::vector<std::string>,std::vector<std::vector<Table::ValueType>>> selectedResults;
    std::priority_queue<std::string,std::vector<std::string>,std::less<>> totalResults;
    bool initted = false;
    std::mutex initMutex;
public:
    bool iswrite(){return false;}
    bool dividable(){return true;}
    std::string getname(){return "SELECT";}
    using ComplexQuery::ComplexQuery;
    void combine(std::priority_queue<std::string,std::vector<std::string>,std::less<>> cnt){
        this->glock();
        while (!cnt.empty()){
            totalResults.push(cnt.top());
            cnt.pop();
        }
        this->decgroup();
        if (this->getGroups()==0){
            this->gunlock();
            auto &db = Database::getInstance();
            while(!totalResults.empty()){
                selectedResults.first.push_back(totalResults.top());
                totalResults.pop();
            }

            for (auto ob:selectedResults.first){
                std::vector<Table::ValueType> temp;
                auto &db = Database::getInstance();
                auto &table = db[this->targetTable];
                auto tuple = table[ob];
                for (size_t i = 1; i < operands.size(); i++) {
                    temp.push_back((*tuple)[operands[i]]);
                }
                selectedResults.second.push_back(temp);
            }
            db.insertResult(this->getId(),std::make_unique<SuccessMsgResult>(selectedResults));
        }
        else this->gunlock();
    }
    QueryResult::Ptr execute() override;

    std::string toString() override;
};
#endif //PROJECT_SELECTQUERY_H
