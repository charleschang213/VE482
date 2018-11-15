#include "../../db/Database.h"
#include "../data/DeleteQuery.h"

void DivQuery::DeleteDivExe(){
    using namespace std;
    auto &db = Database::getInstance();
    auto &table = db[target];
    auto &query = db.results[id].first;
    auto q = dynamic_cast<DeleteQuery*>(query.get());
    int cnt = 0;
    q->init();
    std::vector<std::pair<Table::KeyType,std::vector<Table::ValueType> > > nt = std::vector<std::pair<Table::KeyType,std::vector<Table::ValueType> > >();
    auto result = q->initCondition(table);
    if (result.second){
        for (auto it = table.begin()+counter*Partnumber;it!=table.end()&&it<table.begin()+(counter+1)*Partnumber;it++){
            if (q->evalCondition(*it)){
                ++cnt;
            }
            else {
                vector<int> data;
                for (auto i: table.field()) data.push_back((*it)[i]);
                nt.emplace_back(it->key(),data);
            }
        }
    }
    q->combine(counter,cnt,nt);
}