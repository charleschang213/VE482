#ifndef SRC_DB_H
#define SRC_DB_H

#include "db_table.h"
#include <string>
#include <memory>
#include <unordered_map>

class Database {
    static std::unique_ptr<Database> instance;

    std::unordered_map<std::string, std::unique_ptr<Table>> tables;
    //List of tables

    Database() = default;

public:
    void         registerTable(Table::Ptr &&table);
    //Add a table into the database

    void         dropTable(std::string tableName);
    //Drop a table from database

    void         printAllTable();
    //Database Overview

    Table&       operator[](std::string tableName);
    const Table& operator[](std::string tableName) const;
    //Return a table ofthe name tableName

    Database&    operator=(const Database&) = delete;
    Database&    operator=(Database&&)      = delete;
                 Database(const Database&)  = delete;
                 Database(Database&&)       = delete;
    //Functions of no use

    ~Database() = default;
    //default destructor

    static
    Database&    getInstance() {
        if (Database::instance == nullptr) {
            instance = std::unique_ptr<Database>(new Database);
        }
        return *instance;
    }
};

#endif //SRC_DB_H
