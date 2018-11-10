//
// Created by liu on 18-10-25.
//

#ifndef PROJECT_QUERY_H
#define PROJECT_QUERY_H

#include "QueryResult.h"
#include "../db/Table.h"
#include "DivQuery.h"

#include <functional>
#include <memory>
#include <string>

struct QueryCondition {
    std::string field;
    size_t fieldId;
    std::string op;
    std::function<bool(const Table::ValueType &, const Table::ValueType &)> comp;
    std::string value;
    Table::ValueType valueParsed;
};

class Query {
protected:
    std::string targetTable;
    int id = -1;

public:
    virtual bool isupdate(){return false;}
    Query() = default;

    void setid(const int x){id = x;}

    int getid(){return id;}

    explicit Query(std::string targetTable) : targetTable(std::move(targetTable)) {}

    typedef std::unique_ptr<Query> Ptr;

    virtual QueryResult::Ptr execute() = 0;

    virtual std::string toString() = 0;

    virtual ~Query() = default;
};

class NopQuery : public Query {
public:
    QueryResult::Ptr execute() override {
        return std::make_unique<NullQueryResult>();
    }

    std::string toString() override {
        return "QUERY = NOOP";
    }
};

class DividableQuery: public Query {
    private:
        int DivNum = 0;
        std::vector<DivQuery::Ptr> Tasks;
        std::mutex TaskMutex;
    public:
        explicit DividableQuery(std::string targetTable) : Query(std::move(targetTable)) {}
        virtual bool Dividable(){return true;}
        QueryResult::Ptr combine(int counter);
        template<class DivType>
        void AddDiv(Database &db, Table &table){
            auto begin = table->begin();
            auto size = table->size();
            decltype(begin) end;
            TaskMutex.lock();
            if (size==0){
                auto task = std::unique_ptr<DivType>(new DivType(this,&table,begin,begin));
                auto t = task.get();
                Tasks.emplace_back(std::move(task));
                db.InsertDivQuery(t);
            }
            else{
                const int onediv = 100;
                DivNum = (size-1)/onediv+1;
                while (size>0){
                    if (size>=onediv){
                        size-=onediv;
                        end = begin+onediv;
                    }
                    else{
                        size=0;
                        end = table.end();
                    }
                    auto task = std::unique_ptr<TaskType>(new TaskType(this, &table, begin, end));
                    auto t = task.get();
                    tasks.emplace_back(std::move(task));
                    db.addTask(t);
                    begin = end;
                }
            }
            TaskMutex.unlock();
        }
        template<class DivType>
        void AddOne(Database &db, Table *table){
            auto task = std::unique_ptr<TaskType>(new TaskType(this, table));
            auto t = task.get();
            Tasks.emplace_back(std::move(task));
            db.InsertDivQuery(t);
        }
        void SetDivNum(const int x){DivNum=x;}
}

class ComplexQuery : public DividableQuery {
protected:
    /** The field names in the first () */
    std::vector<std::string> operands;
    /** The function used in where clause */
    std::vector<QueryCondition> condition;
public:
    typedef std::unique_ptr<ComplexQuery> Ptr;

    /**
     * init a fast condition according to the table
     * note that the condition is only effective if the table fields are not changed
     * @param table
     * @param conditions
     * @return a pair of the key and a flag
     * if flag is false, the condition is always false
     * in this situation, the condition may not be fully initialized to save time
     */
    std::pair<std::string, bool> initCondition(const Table &table);

    /**
     * skip the evaluation of KEY
     * (which should be done after initConditionFast is called)
     * @param conditions
     * @param object
     * @return
     */
    bool evalCondition(const Table::Object &object);

    /**
     * This function seems have small effect and causes somme bugs
     * so it is not used actually
     * @param table
     * @param function
     * @return
     */
    bool testKeyCondition(Table &table, std::function<void(bool, Table::Object::Ptr &&)> function);


    ComplexQuery(std::string targetTable,
                 std::vector<std::string> operands,
                 std::vector<QueryCondition> condition)
            : DividableQuery(std::move(targetTable)),
              operands(std::move(operands)),
              condition(std::move(condition)) {
    }

    /** Get operands in the query */
    const std::vector<std::string> &getOperands() const { return operands; }

    /** Get condition in the query, seems no use now */
    const std::vector<QueryCondition> &getCondition() { return condition; }
};

#endif //PROJECT_QUERY_H
