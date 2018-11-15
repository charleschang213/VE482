

#ifndef PROJECT_SUBQUERY_H
#define PROJECT_SUBQUERY_H

#include "../Query.h"

class SubQuery : public ComplexQuery {
    friend class DivQuery;
    static constexpr const char *qname = "SUB";
    int counter = 0;
public:
    std::string getname(){return "SUB";}
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

    QueryResult::Ptr execute() override;

    std::string toString() override;
};


#endif //PROJECT_SUBQUERY_H
