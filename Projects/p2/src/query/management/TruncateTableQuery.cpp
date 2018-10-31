#include "TruncateTableQuery.h"
#include "../../db/Database.h"

constexpr const char *TruncateTableQuery::qname;

QueryResult::Ptr TruncateTableQuery::execute() {
    using namespace std;
    Database &db = Database::getInstance();
    db[targetTable].clear();
    return make_unique<NullQueryResult>();
}

std::string TruncateTableQuery::toString() {
    return "";
}