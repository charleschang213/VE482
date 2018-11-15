//
// Created by liu on 18-10-25.
//

#ifndef PROJECT_QUERY_H
#define PROJECT_QUERY_H
#include "../db/Database.h"
#include "QueryResult.h"
#include "../db/Table.h"

#include <functional>
#include <memory>
#include <string>

class DivQuery;

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
    int groups = 0;
    std::mutex gMutex;

public:
    virtual void init(){}
    void glock(){gMutex.lock();}
    void gunlock(){gMutex.unlock();}
    QueryResult::Ptr result = nullptr;
    virtual bool uniquery(){return false;}
    virtual bool iscreate(){return false;}
    virtual std::string getname(){return "";}
    virtual std::pair<std::string, bool> initCondition(const Table &table){return std::pair<std::string,bool>("",true);};
    virtual  bool evalCondition(const Table::Object &object){return true;};
    virtual void dump(){}
    virtual bool dividable(){return false;}
    virtual bool iswrite(){return false;}
    Query() = default;

    void finish(){}
    void setId(int x){id=x;}
    int getId(){return id;}
    void setGroups(int x){groups=x;}
    void decgroup(){groups--;}
    int getGroups(){return groups;}

    explicit Query(std::string targetTable) : targetTable(std::move(targetTable)) {}

    typedef std::unique_ptr<Query> Ptr;

    std::string getTableName(){return targetTable;}

    virtual QueryResult::Ptr execute(){return std::make_unique<NullQueryResult>();}

    virtual std::string toString(){return "";}

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

class ComplexQuery : public Query {
protected:
    /** The field names in the first () */
    std::vector<std::string> operands;
    /** The function used in where clause */
    std::vector<QueryCondition> condition;
public:
    bool dividable(){return true;}
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
            : Query(std::move(targetTable)),
              operands(std::move(operands)),
              condition(std::move(condition)) {
    }

    /** Get operands in the query */
    const std::vector<std::string> &getOperands() const { return operands; }

    /** Get condition in the query, seems no use now */
    const std::vector<QueryCondition> &getCondition() { return condition; }
};


#endif //PROJECT_QUERY_H
