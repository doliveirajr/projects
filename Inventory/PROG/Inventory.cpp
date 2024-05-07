#include "../INCLUDE/Inventory.hpp"

void Inventory::createDB(std::string sql_)
{
    sqlite3 *DB;
    exit_ = sqlite3_open("Inventory.db", &DB);
    exit_ = sqlite3_exec(DB, sql_.c_str(), NULL, 0, &messaggeError_);
    if (exit_ != SQLITE_OK)
    {
        std::cerr << "Error Create Table: " << messaggeError_ << std::endl;
        sqlite3_free(messaggeError_);
    }
    else
        std::cout << "Table created Successfully!" << std::endl;
}

int Inventory::callback(void *data, int argc, char **argv, char **azColName)
{
    sqlite3 *DB;
    int exit = 0;
    exit = sqlite3_open("Inventory.db", &DB);
    int i;
    fprintf(stderr, "%s: ", (const char *)data);

    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void Inventory::callcallback(std::string query_)
{
    sqlite3_open("Inventory.db", &DB);
    sqlite3_exec(DB, query_.c_str(), callback, NULL, NULL);
}

void Inventory::updateDB(std::string sql_)
{
    sqlite3 *DB;
    exit_ = sqlite3_open("Inventory.db", &DB);
    exit_ = sqlite3_exec(DB, sql_.c_str(), NULL, 0, &messaggeError_);
    if (exit_ != SQLITE_OK)
    {
        std::cerr << "Error Insert" << messaggeError_ << std::endl;
    }
    else
        std::cout << "Records created Successfully!" << std::endl;
}

void Inventory::deleteDB(std::string sql_)
{
    sqlite3 *DB;
    exit_ = sqlite3_open("Inventory.db", &DB);
    exit_ = sqlite3_exec(DB, sql_.c_str(), NULL, 0, &messaggeError_);
    if (exit_ != SQLITE_OK)
    {
        std::cerr << "Error DELETE: " << messaggeError_ << std::endl;
        sqlite3_free(messaggeError_);
    }
    else
        std::cout << "Record deleted Successfully!" << std::endl;

}

int main(int argc, char const *argv[])
{
    Inventory a;
    auto c = ("CREATE TABLE INVENTORY("
              "ID INT PRIMARY KEY	 NOT NULL, "
              "NAME		 TEXT NOT NULL, "
              "PRICE		 REAL	 NOT NULL, "
              "QUANTITY		 INT	 NOT NULL );");
    a.createDB(c);
    std::string query = "SELECT * FROM INVENTORY;";
    auto u = ("INSERT INTO INVENTORY VALUES(1, 'TV', 2455.0, 48);"
              "INSERT INTO INVENTORY VALUES(2, 'PS5', 2000.5, 25);"
              "INSERT INTO INVENTORY VALUES(3, 'NOTEBOOK', 2950.0, 20);");

    a.updateDB(u);
    a.callcallback(query);
    auto d = "DELETE FROM INVENTORY;";
    a.deleteDB(d);

    return 0;
}