#include "CopyTableQuery.h"
#include "../../db/Database.h"

constexpr const char *CopyTableQuery::qname;

QueryResult::Ptr CopyTableQuery::execute() {
    using namespace std;
    Database &db = Database::getInstance();
    auto &target = db[this->targetTable];
    auto table = std::make_unique<Table>(NewTable, target);
    db.registerTable(std::move(table));
    return make_unique<NullQueryResult>(qname, targetTable);

}

std::string CopyTableQuery::toString() {
    return "";
}