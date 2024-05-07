#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <iostream>
#include <sqlite3.h>

class Inventory
{
private:
    std::string query_{""};
    std::string sql_{""};
    int exit_{0};
    char *messaggeError_;
    sqlite3 *DB;
public:
    void createDB(std::string sql_);
    static int callback(void *data, int argc, char **argv, char **azColName);
    void updateDB(std::string sql_);
    void deleteDB(std::string sql_);
    void callcallback(std::string query_);
    Inventory() = default;
    ~Inventory(){ sqlite3_close(DB);}
};




#endif