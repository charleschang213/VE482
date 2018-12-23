#include "../../db/Database.h"
#include "../data/SwapQuery.h"

void DivQuery::SwapDivExe()
{
    using namespace std;
    auto &db = Database::getInstance();
    auto &table = db[target];
    auto &query = db.results[id].first;
    auto q = dynamic_cast<SwapQuery *>(query.get());
    int cnt = 0;
    Table::ValueType value;
    auto result = q->initCondition(table);
    if (result.second)
    {
        for (auto it = table.begin() + counter * Partnumber; it != table.end() && it < table.begin() + (counter + 1) * Partnumber; it++)
        {
            if (q->evalCondition(*it))
            {
                value = (*it)[q->operands[0]];
                (*it)[q->operands[0]] = (*it)[q->operands[1]];
                (*it)[q->operands[1]] = value;
                ++cnt;
            }
        }
    }
    q->combine(cnt);
}