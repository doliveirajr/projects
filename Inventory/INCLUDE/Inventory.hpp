#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <iostream>
#include <sqlite3.h>

class Inventory
{
private:
    
    int exit_{0};
    char *messaggeError_;
    sqlite3 *DB;

public:
    bool createDB(std::string sql_);
    static int readDB(void *data, int argc, char **argv, char **azColName);
    bool updateDB(std::string sql_);
    bool deleteDB(std::string sql_);
    bool callReadDB(std::string query_);
    Inventory() = default;
    ~Inventory() { sqlite3_close(DB); }
};

#endif