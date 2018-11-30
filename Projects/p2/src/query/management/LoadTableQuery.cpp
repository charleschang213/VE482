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
        std::string a = this->fileName;
        if (a.find("..")==0) a = a.substr(1);
        ifstream infile(a);
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
