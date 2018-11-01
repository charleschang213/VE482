//
//  MinQuery.cpp
//  
//
//  Created by Sienna on 2018/11/1.
//
//

#include <vector>
#include "MinQuery.h"
#include "../../db/Database.h"

constexpr const char *MinQuery::qname;

QueryResult::Ptr MinQuery::execute() {
    using namespace std;
    
    if (this->operands.size() < 1)
        return make_unique<ErrorMsgResult>(
                                           qname, this->targetTable.c_str(),
                                           "Invalid number of operands (? operands)."_f % operands.size()
                                           );
    Database &db = Database::getInstance();
    try {
        vector<Table::ValueType> Minimum;
        auto &table = db[this->targetTable];
        auto result = initCondition(table);
        if (result.second) {
            for (auto it = table.begin(); it != table.end(); ++it)
            {
                if (this->evalCondition(*it))
                {
                    for (size_t cnt = 0; cnt < operands.size(); cnt++)
                    {
                        if (Minimum.size() < operands.size()) //The first row.
                            Minimum.push_back((*it)[operands[cnt]]);
                        else
                            Minimum[cnt] = (Minimum[cnt] < (*it)[operands[cnt]])?Minimum[cnt]:(*it)[operands[cnt]];
                    }
                }
            }
        }
        return make_unique<SuccessMsgResultDerv>(Minimum);
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

std::string MinQuery::toString() {
    return "QUERY = MIN " + this->targetTable + "\"";
}
