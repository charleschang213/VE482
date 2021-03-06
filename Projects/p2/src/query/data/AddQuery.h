

#ifndef PROJECT_ADDQUERY_H
#define PROJECT_ADDQUERY_H

#include "../Query.h"

class AddQuery : public ComplexQuery {
    friend class DivQuery;
    static constexpr const char *qname = "ADD";
    int counter = 0;

public:
    bool iswrite() override {return true;}
    bool dividable() override {return true;}
    std::string getname() override {return "ADD";}
    using ComplexQuery::ComplexQuery;
    void combine(int cnt){
        this->glock();
        this->counter+=cnt;
        this->decgroup();
        if (this->getGroups()==0){
            this->gunlock();
            auto &db = Database::getInstance();
            db.insertResult(this->getId(),std::make_unique<RecordCountResult>(counter));
        }
        else this->gunlock();
    }

    //QueryResult::Ptr execute() override;

    //std::string toString() override;
};


#endif //PROJECT_ADDQUERY_H
