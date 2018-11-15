#ifndef DELETEQUERY_H
#define DELETEQUERY_H
#include "../Query.h"

class DeleteQuery : public ComplexQuery {
    static constexpr const char *qname = "DELETE";
    std::vector<std::vector<std::pair<Table::KeyType,std::vector<Table::ValueType> > > > newtable = std::vector<std::vector<std::pair<Table::KeyType,std::vector<Table::ValueType> > > >();
    int counter = 0;
public:
    bool iswrite() override {return true;}
    std::string getname() override {return "DELETE";}
    using ComplexQuery::ComplexQuery;
    //QueryResult::Ptr execute() override;

    void combine(int gcnt,int cnt, std::vector<std::pair<Table::KeyType,std::vector<Table::ValueType> > > nt){
        this->glock();
        counter += cnt;
        if (newtable.empty()) newtable = std::vector<std::vector<std::pair<Table::KeyType,std::vector<Table::ValueType> > > >(this->getGroups());
        newtable[gcnt] = nt;
        this->decgroup();
        if (this->getGroups()==0){
            this->gunlock();
            auto &db = Database::getInstance();
            auto &table = db[this->targetTable];
            table.clear();
            for (auto i:newtable){
                for (auto j:i)
                    table.insertByIndex(j.first,std::move(j.second));
            }
            db.insertResult(this->getId(),std::make_unique<RecordCountResult>(counter));
        }
        this->gunlock();
    }

    //std::string toString() override;
};

#endif