#include "../../db/Database.h"
#include "DeleteQuery.h"

#include "../QueryResult.h"

#include <algorithm>
#include<vector>
#include<utility>

constexpr const char *DeleteQuery::qname;

QueryResult::Ptr DeleteQuery::execute() {
    using namespace std;
    Database &db = Database::getInstance();
    auto &table = db[this->targetTable];
    auto result = initCondition(table);
    Table newtable(table.name(),table.field());
    Table::SizeType counter = 0;
    vector<pair<string, vector<int> > > kvp;
    if (result.second){
        for (auto it = table.begin();it!=table.end();it++){
            if (this->evalCondition(*it)){
                counter++;
            }
            else {
                vector<int> data;
                for (auto i: table.field()) data.push_back((*it)[i]);
                kvp.emplace_back(it->key(),data);
            }
        }
    }
    table.clear();
    for (auto it: kvp){
        table.insertByIndex(it.first,std::move(it.second));
    }
    return std::make_unique<RecordCountResult>(counter);

}

std::string DeleteQuery::toString() {
    return "QUERY = DELETE " + this->targetTable + "\"";
}
