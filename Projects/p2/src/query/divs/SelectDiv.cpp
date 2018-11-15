//
// Created by cat on 18-11-15.
//
#include "../../db/Database.h"
#include "../data/SelectQuery.h"

void DivQuery::SelectDivExe() {
    using namespace std;
    auto &db = Database::getInstance();
    auto &table = db[target];
    auto &query = db.results[id].first;
    auto q = dynamic_cast<SelectQuery *>(query.get());
    std::priority_queue<string, std::vector<string>, std::less<std::string>> cntResults;
    auto result = q->initCondition(table);
    if (result.second) {
        for (auto it = table.begin() + counter * Partnumber;
             it != table.end() && it < table.begin() + (counter + 1) * Partnumber; it++) {
            if (q->evalCondition(*it)) {
                cntResults.push(it->key());
            }
        }
    }
    q->combine(cntResults);
}