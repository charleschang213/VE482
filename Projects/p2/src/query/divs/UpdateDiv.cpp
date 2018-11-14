#include "../../db/Database.h"
#include "../data/UpdateQuery.h"

QueryResult::Ptr DivQuery::UpdateDivExe(){
    using namespace std;
    auto &db = Database::getInstance();
    auto &table = db[target];
    auto &query = db.results[id].first;
    auto q = dynamic_cast<UpdateQuery*>(query.get());
    int counter = 0;
    auto result = q->initCondition(table);
    if (result.second){
        for (auto it = table.begin()+counter*Partnumber;it<table.begin()+(counter+1)*Partnumber;it++){
            if (q->evalCondition(*it)){
                if (q->keyValue.empty()) {
                        (*it)[q->fieldId] = q->fieldValue;
                    } else {
                        it->setKey(q->keyValue);
                    }
                ++counter;
            }
        }
    }
    return make_unique<RecordCountResult>(counter);    
}