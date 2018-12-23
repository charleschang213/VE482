//
// Created by cat on 18-11-15.
//
#include "../../db/Database.h"
#include "../data/DuplicateQuery.h"
void DivQuery::DuplicateDivExe() {
    using namespace std;
    auto &db = Database::getInstance();
    auto &table = db[target];
    auto &query = db.results[id].first;
    auto q = dynamic_cast<DuplicateQuery*>(query.get());
    auto result = q->initCondition(table);
    //vector<vector<Table::ValueType >> cntvector;
    int cnt = 0;
    if (result.second) {
        for (auto it = table.begin()+counter*Partnumber; it != table.end()&&it< table.begin()+(counter+1)*Partnumber; ++it) {
            if (query->evalCondition(*it)) {
                if (table.dup(it)) {
                   cnt++;
                }
            }
        }
    }
    q->combine(cnt);
}