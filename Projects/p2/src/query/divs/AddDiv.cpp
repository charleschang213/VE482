#include "../../db/Database.h"
#include "../data/AddQuery.h"

void DivQuery::AddDivExe(){
    using namespace std;
    auto &db = Database::getInstance();
    auto &table = db[target];
    auto &query = db.results[id].first;
    auto q = dynamic_cast<AddQuery*>(query.get());
    int cnt = 0;
    Table::ValueType value;
    auto result = q->initCondition(table);
    if (result.second){
        for (auto it = table.begin()+counter*Partnumber;it!=table.end()&&it<table.begin()+(counter+1)*Partnumber;it++){
            if (q->evalCondition(*it)){
                    value = (*it)[q->operands[0]];
                    for(int i=1;i<q->operands.size()-1;i++){
                        value=value+(*it)[q->operands[i]];
                    }
                    (*it)[q->operands[q->operands.size()-1]]=value;
                    ++cnt;
            }
        }
    }
    q->combine(cnt); 
}