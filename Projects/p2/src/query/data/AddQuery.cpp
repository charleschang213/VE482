#include "../../db/Database.h"
#include "AddQuery.h"


constexpr const char *AddQuery::qname;

QueryResult::Ptr AddQuery::execute() {
    using namespace std;
    if (this->operands.size() < 2)
        return make_unique<ErrorMsgResult>(
                qname, this->targetTable.c_str(),
                "Invalid number of operands (? operands)."_f % operands.size()
        );
    Database &db = Database::getInstance();
    Table::SizeType counter = 0;
    Table::ValueType value;
    try {
        auto &table = db[this->targetTable];
        /*if (this->operands[0] == "KEY") {
            this->keyValue = this->operands[1];
        } else {
            this->fieldId = table.getFieldIndex(this->operands[0]);
            this->fieldValue = (Table::ValueType) strtol(this->operands[1].c_str(), nullptr, 10);
        }*/
        auto result = initCondition(table);
        if (result.second) {
            for (auto it = table.begin(); it != table.end(); ++it) {
                if (this->evalCondition(*it)) {
		    value = (*it)[this->operands[0]];
		    for(uint i=1;i<this->operands.size()-1;i++){
		    	value=value+(*it)[this->operands[i]];
		    }
		    (*it)[this->operands[operands.size()-1]]=value;
                    ++counter;
                }
            }
        }
        return make_unique<RecordCountResult>(counter);
    } catch (const TableNameNotFound &e) {
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

std::string AddQuery::toString() {
    return "QUERY = ADD " + this->targetTable + "\"";
}
