#ifndef PAYROLL_HPP
#define PAYROLL_HPP
#include <iostream>
#include <sqlite3.h>

enum class Role
{
    ENGINEER = 1,
    MECHANIC,
    TECHNICIAN,
    INTERN
};

class Payroll
{
private:
    int exit_{0};
    char *messaggeError_;
    sqlite3 *DB;
    std::string name_{""};
    std::string role_{""};
    double workedHours_{0};
    double payment_{0};

public:
    bool createDB(std::string sql);
    static int readDB(void *data, int argc, char **argv, char **azColName);
    bool updateDB(std::string sql);
    bool deleteDB(std::string sql);
    bool callReadDB(std::string query);

    void setName(std::string name);
    void setRole(Role roleNumber);
    void setWorkedHours(double workedHours);
    double calculatePayroll(double workedHours);

    std::string createInsertSqlString(std::string name, std::string role, double workedHours, double payment);
    std::string getName();
    double getWorkedHours();
    std::string getRole();

    void reset();

    Payroll() { reset(); };
    ~Payroll() { sqlite3_close(DB); };
};

#endif