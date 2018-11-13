//
// Created by cat on 18-11-1.
//

#include "../../db/Database.h"
#include "DuplicateQuery.h"
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
    int counter = 0;
    if (result.second) {
        auto it = table.begin();
        auto si = table.size();
        for (size_t i=0; i!=si; ++i) {
            auto oldkey = (it->key());
            if (this->evalCondition(*it)) {
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
                table.insertByIndex(newkey, move(data));
            }
            for (it=table.begin();it->key()!=oldkey;++it);
            ++it;
        }
    }
    return make_unique<RecordCountResult>(counter);
}


std::string DuplicateQuery::toString() {
    return "QUERY = DUPLICATE " + this->targetTable + "\"";
}