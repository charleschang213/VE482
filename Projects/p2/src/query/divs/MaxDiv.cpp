#include "../../db/Database.h"
#include "../data/MaxQuery.h"
#include <vector>

void DivQuery::MaxDivExe(){
    using namespace std;
    auto &db = Database::getInstance();
    auto &table = db[target];
    auto &query = db.results[id].first;
    auto q = dynamic_cast<MaxQuery*>(query.get());
    //int cnt = 0;
    //q->init();
    vector<Table::ValueType> Maximum;
    auto result = q->initCondition(table);
    if (result.second) {
        for (auto it = table.begin() + counter * Partnumber; it != table.end() && it < table.begin() + (counter + 1) * Partnumber; it++)
        {
            if (q->evalCondition(*it))
            {
                for (size_t i = 0; i < q->operands.size(); i++)
                {
                    if (Maximum.size() < q->operands.size()) //The first row.
                        Maximum.push_back((*it)[q->operands[i]]);
                    else
                        Maximum[i] = (Maximum[i] > (*it)[q->operands[i]])?Maximum[i]:(*it)[q->operands[i]];
                }
                //++cnt;
            }
        }
    }
    q->combine(Maximum);
}
