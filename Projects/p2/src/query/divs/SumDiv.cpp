#include "../../db/Database.h"
#include "../data/SumQuery.h"
#include <vector>

void DivQuery::UpdateDivExe(){
    using namespace std;
    auto &db = Database::getInstance();
    auto &table = db[target];
    auto &query = db.results[id].first;
    auto q = dynamic_cast<SumQuery*>(query.get());
    //int cnt = 0;
    //q->init();
    vector<Table::ValueType> SumResult;
    auto result = q->initCondition(table);
    if (result.second) {
        for (size_t i = 0; i < q->operands.size(); i++)
        {
            SumResult.push_back(0);
        }
        for (auto it = table.begin() + counter * Partnumber; it != table.end() && it < table.begin() + (counter + 1) * Partnumber; it++)
        {
            if (q->evalCondition(*it))
            {
                for (size_t i = 0; i < q->operands.size(); i++)
                    SumResult[i] = SumResult[i] + (*it)[q->operands[i]];
            }
        }
    }
    q->combine(SumResult);
}
