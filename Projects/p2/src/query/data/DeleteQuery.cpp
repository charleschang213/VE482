#include "DeleteQuery.h"
#include "../../db/Database.h"
#include "../QueryResult.h"

#include <algorithm>

constexpr const char *DeleteQuery::qname;

QueryResult::Ptr DeleteQuery::execute() {
    using namespace std;
    Database &db = Database::getInstance();
    auto &table = db[this->targetTable];
    auto result = initCondition(table);
    Table newtable(table.name(),table.field());
    Table::SizeType counter = 0;
    if (result.second){
        for (auto it = table.begin();it!=table.end();it++){
            if (this->evalCondition(*it)){
                counter++;
            }
            else {
                newtable.insertByIndex(it->key(),table[it->key()]);
            }
        }
    }
    db[this->targetTable] = newtable;
    return std::make_unique<SuccessMsgResult>(qname, targetTable);

}

std::string DeleteQuery::toString() {
    return "QUERY = DELETE " + this->targetTable + "\"";
}
