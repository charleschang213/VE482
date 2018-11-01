//
// Created by cat on 18-11-1.
//

#include "DuplicateQuery.h"
#include "../../db/Database.h"
#include <iostream>

constexpr const char *DuplicateQuery::qname;

QueryResult::Ptr DuplicateQuery::execute() {
    using namespace std;
    /*
    if (this->operands.size() != 2)
        return make_unique<ErrorMsgResult>(
                qname, this->targetTable.c_str(),
                "Invalid number of operands (? operands)."_f % operands.size()
        );
        */
    Database &db = Database::getInstance();

    auto &table = db[this->targetTable];
    auto result = initCondition(table);
    if (result.second) {
        auto it = table.begin();
        auto si = table.size();
        for (size_t i=0; i!=si; ++i) {
            if (this->evalCondition(*it)) {
                auto newkey = (it->key());
                newkey+="_copy";
                while (table[newkey]!=nullptr) newkey+="_copy";
                vector<Table::ValueType> data;
                data.reserve(table.field().size());
                for (size_t i = 0; i < table.field().size(); ++i) {
                    data.push_back((*it)[i]);
                    //data.push_back((*it)[table.field()[i]]);
                }
                table.insertByIndex(newkey, move(data));
            }
            ++it;
        }
    }
    return make_unique<NullQueryResult>();
}


std::string DuplicateQuery::toString() {
    return "QUERY = DUPLICATE " + this->targetTable + "\"";
}