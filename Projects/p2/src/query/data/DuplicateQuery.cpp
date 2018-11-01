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

        for (auto it = table.begin(); it != table.end(); ++it) {
            if (this->evalCondition(*it)) {
                auto newkey = (it->key() + "_copy");
                for (auto itt = it + 1; itt != table.end(); ++itt) {
                    if (newkey == itt->key())newkey += "_copy";
                }
                vector<Table::ValueType> data;
                data.reserve(table.field().size());
                for (size_t i = 0; i < table.field().size(); ++i) {
                    data.push_back((*it)[i]);
                    //data.push_back((*it)[table.field()[i]]);
                }
                table.insertByIndex(newkey, move(data));
            }
        }
    }
    return make_unique<NullQueryResult>();
}


std::string DuplicateQuery::toString() {
    return "QUERY = DUPLICATE " + this->targetTable + "\"";
}