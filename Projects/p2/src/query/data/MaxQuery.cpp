//
//  MaxQuery.cpp
//  
//
//  Created by Sienna on 2018/11/1.
//
//

#include "../../db/Database.h"
#include <vector>
#include "MaxQuery.h"

constexpr const char *MaxQuery::qname;

QueryResult::Ptr MaxQuery::execute() {
    using namespace std;
    
    if (this->operands.size() < 1)
        return make_unique<ErrorMsgResult>(
                                           qname, this->targetTable.c_str(),
                                           "Invalid number of operands (? operands)."_f % operands.size()
                                           );
    Database &db = Database::getInstance();
    try {
        vector<Table::ValueType> Maximum;
        auto &table = db[this->targetTable];
        auto result = initCondition(table);
        if (result.second) {
            for (auto it = table.begin(); it != table.end(); ++it)
            {
                if (this->evalCondition(*it))
                {
                    for (size_t cnt = 0; cnt < operands.size(); cnt++)
                    {
                        if (Maximum.size() < operands.size()) //The first row.
                            Maximum.push_back((*it)[operands[cnt]]);
                        else
                            Maximum[cnt] = (Maximum[cnt] > (*it)[operands[cnt]])?Maximum[cnt]:(*it)[operands[cnt]];
                    }
                }
            }
        }
        return make_unique<SuccessMsgResultDerv>(Maximum);
    }
    
      catch (const TableNameNotFound &e) {
        return make_unique<ErrorMsgResult>(qname, this->targetTable, "No such table."s);
    } catch (const IllFormedQueryCondition &e) {
        return make_unique<ErrorMsgResult>(qname, this->targetTable, e.what());
    } catch (const invalid_argument &e) {
        // Cannot convert operand to string
        return make_unique<ErrorMsgResult>(qname, this->targetTable, "Unknown error '?'"_f % e.what());
    } catch (const exception &e) {
        return make_unique<ErrorMsgResult>(qname, this->targetTable, "Unkonwn error '?'."_f % e.what());
    }
}

std::string MaxQuery::toString() {
    return "QUERY = MAX " + this->targetTable + "\"";
}
