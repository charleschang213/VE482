//
// Created by cat on 18-11-1.
//

#include "SelectQuery.h"
#include "../../db/Database.h"
#include <iostream>

constexpr const char *SelectQuery::qname;

QueryResult::Ptr SelectQuery::execute() {
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
                cout.flush();
                cout << "( " << it->key();
                cout.flush();
                for (size_t i = 1; i < operands.size(); i++) {
                    cout.flush();
                    cout << " " << (*it)[operands[i]];
                    cout.flush();
                }
                cout.flush();
                cout << " )\n";
                cout.flush();
            }
        }
    }

    return make_unique<NullQueryResult>();
}

std::string SelectQuery::toString() {
    return "QUERY = SELECT " + this->targetTable + "\"";
}