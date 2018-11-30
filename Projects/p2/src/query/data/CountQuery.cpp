//
// Created by cat on 18-11-1.
//


#include "../../db/Database.h"
#include "CountQuery.h"
#include <iostream>

constexpr const char *CountQuery::qname;

QueryResult::Ptr CountQuery::execute() {
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
    int counter=0;
    if (result.second) {
        for (auto it = table.begin(); it != table.end(); ++it) {
            if (this->evalCondition(*it)) {
               counter++;
            }
        }
    }
    cout.flush();
    cout<<"ANSWER = "<<counter <<endl;
    cout.flush();
    return make_unique<NullQueryResult>();
}

std::string CountQuery::toString() {
    return "QUERY = COUNT " + this->targetTable + "\"";
}
