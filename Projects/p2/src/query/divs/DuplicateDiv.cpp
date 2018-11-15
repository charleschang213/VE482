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
    pair<vector<string>,vector<vector<Table::ValueType >>> cntvector;
    if (result.second) {
        auto it = table.begin();
        auto si = table.size();
        for (size_t i=0; i!=si; ++i) {
            auto oldkey = (it->key());
            if (q->evalCondition(*it)) {
                auto newkey = (it->key());
                newkey+="_copy";
                if (table[newkey]!=nullptr) {
                    ++it;
                    continue;
                }
                counter++;
                vector<Table::ValueType> data;
                data.reserve(table.field().size());
                for (size_t j = 0; j < table.field().size(); ++j) {
                    data.push_back((*it)[j]);
                    //data.push_back((*it)[table.field()[i]]);
                }
                cntvector.first.push_back(newkey);
                cntvector.second.push_back(data);
                //table.insertByIndex(newkey, move(data));
            }
            for (it=table.begin();it->key()!=oldkey;++it);
            ++it;
        }
    }
    q->combine(cntvector);
}