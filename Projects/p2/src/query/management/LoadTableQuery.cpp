//
// Created by liu on 18-10-25.
//
#include "../../db/Database.h"
#include "LoadTableQuery.h"


#include <fstream>
#include <iostream>

constexpr const char *LoadTableQuery::qname;

QueryResult::Ptr LoadTableQuery::execute() {
    using namespace std;
    Database &db = Database::getInstance();
    try {
        ifstream infile(this->fileName);
        if (this->fileName.find("..")==0) this->fileName = this->fileName.substr(1);
        if (!infile.is_open()) {      
            std::cerr << "LOAD file " << this->fileName << " failed." << std::endl;
            return make_unique<ErrorMsgResult>(qname, "Cannot open file '?'"_f % this->fileName);
        }
        db.loadTableFromStream(infile, this->fileName);
        infile.clear();
        infile.close();
        std::cerr << "LOAD file " << this->fileName << " succeeded." << std::endl;
        return make_unique<SuccessMsgResult>(qname, targetTable);
    } catch (const exception &e) {
        std::cerr << "LOAD fail" << std::endl;
        return make_unique<ErrorMsgResult>(qname, e.what());
    }
}

std::string LoadTableQuery::toString() {
    return "QUERY = Load TABLE, FILE = \"" + this->fileName + "\"";
}
