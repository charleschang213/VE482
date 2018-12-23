#include "../../db/Database.h"
#include "CopyTableQuery.h"


constexpr const char *CopyTableQuery::qname;

QueryResult::Ptr CopyTableQuery::execute() {
    using namespace std;
    Database &db = Database::getInstance();
    auto &target = db[NewTable];
    auto table = std::make_unique<Table>(this->targetTable, target);
    db.registerTable(std::move(table));
    return make_unique<NullQueryResult>();

}

std::string CopyTableQuery::toString() {
    return "";
}