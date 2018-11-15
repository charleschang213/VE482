//
// Created by cat on 18-11-15.
//
//
// Created by cat on 18-11-1.
//


#include "../../db/Database.h"
#include "../data/CountQuery.h"
#include <iostream>

void DivQuery::CountDivExe() {
    using namespace std;
    Database &db = Database::getInstance();
    auto &table = db[target];
    auto &query = db.results[id].first;
    auto q = dynamic_cast<CountQuery *>(query.get());
    int cnt = 0;
    auto result = q->initCondition(table);
    if (result.second) {
        for (auto it = table.begin() + counter * Partnumber;
             it != table.end() && it < table.begin() + (counter + 1) * Partnumber; it++) {
            if (q->evalCondition(*it)) {
                cnt++;
            }
        }
    }
    q->combine(cnt);
}

//constexpr const char *CountQuery::qname;



std::string CountQuery::toString() {
    return "QUERY = COUNT " + this->targetTable + "\"";
}

