#include "../INCLUDE/Inventory.hpp"

bool Inventory::createDB(std::string sql_)
{
    sqlite3 *DB;
    exit_ = sqlite3_open("Inventory.db", &DB);
    exit_ = sqlite3_exec(DB, sql_.c_str(), NULL, 0, &messaggeError_);
    if (exit_ != SQLITE_OK)
    {
        std::cerr << "Error Create Table: " << messaggeError_ << std::endl;
        sqlite3_free(messaggeError_);
        return false;
    }
    else
        return true;
}

int Inventory::readDB(void *data, int argc, char **argv, char **azColName)
{
    sqlite3 *DB;
    sqlite3_open("Inventory.db", &DB);
    int i;
    fprintf(stderr, "%s: ", (const char *)data);

    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

bool Inventory::callReadDB(std::string query_)
{
    sqlite3_open("Inventory.db", &DB);
    exit_ = sqlite3_exec(DB, query_.c_str(), readDB, NULL, NULL);
    if (exit_ != SQLITE_OK)
    {
        return false;
    }
    else
        return true;
}

bool Inventory::updateDB(std::string sql_)
{
    sqlite3 *DB;
    exit_ = sqlite3_open("Inventory.db", &DB);
    exit_ = sqlite3_exec(DB, sql_.c_str(), NULL, 0, &messaggeError_);
    if (exit_ != SQLITE_OK)
    {
        std::cerr << "Error Insert" << messaggeError_ << std::endl;
        return false;
    }
    else
        return true;
}

bool Inventory::deleteDB(std::string sql_)
{
    sqlite3 *DB;
    exit_ = sqlite3_open("Inventory.db", &DB);
    exit_ = sqlite3_exec(DB, sql_.c_str(), NULL, 0, &messaggeError_);
    if (exit_ != SQLITE_OK)
    {
        std::cerr << "Error DELETE: " << messaggeError_ << std::endl;
        sqlite3_free(messaggeError_);
        return false;
    }
    else
        return true;
}