#ifndef DELETEQUERY_H
#define DELETEQUERY_H
#include "../Query.h"

class DeleteQuery : public ComplexQuery {
    static constexpr const char *qname = "DELETE";
    int counter = 0;
public:
    bool iswrite() override {return true;}
    std::string getname() override {return "DELETE";}
    using ComplexQuery::ComplexQuery;
    //QueryResult::Ptr execute() override;

    void combine(int cnt){
        this->glock();
        counter += cnt;
        this->decgroup();
        if (this->getGroups()==0){
            this->gunlock();
            auto &db = Database::getInstance();
            auto &table = db[this->targetTable];
            table.swap();
            db.insertResult(this->getId(),std::make_unique<RecordCountResult>(counter));
        }
        this->gunlock();
    }

    //std::string toString() override;
};

#endif