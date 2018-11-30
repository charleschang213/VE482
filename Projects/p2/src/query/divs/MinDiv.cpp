#include "../../db/Database.h"
#include "../data/MinQuery.h"

void DivQuery::MinDivExe(){
    using namespace std;
    auto &db = Database::getInstance();
    auto &table = db[target];
    auto &query = db.results[id].first;
    auto q = dynamic_cast<MinQuery*>(query.get());
    int cnt = 0;
    q->init();
    vector<Table::ValueType> Minimum;
    auto result = q->initCondition(table);
    if (result.second) {
        for (auto it = table.begin() + counter * Partnumber; it != table.end() && it < table.begin() + (counter + 1) * Partnumber; it++)
        {
            if (q->evalCondition(*it))
            {
                for (size_t i = 0; i < q->operands.size(); i++)
                {
                    if (Minimum.size() < q->operands.size()) //The first row.
                        Minimum.push_back((*it)[q->operands[i]]);
                    else
                        Minimum[i] = (Minimum[i] < (*it)[q->operands[i]])?Minimum[i]:(*it)[q->operands[i]];
                }
                ++cnt;
            }
        }
    }
    q->combine(Minimum);
}
