#include "../INCLUDE/Payroll.hpp"

bool Payroll::createDB(std::string sql_)
{
    sqlite3 *DB;
    exit_ = sqlite3_open("Payroll.db", &DB);
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

int Payroll::readDB(void *data, int argc, char **argv, char **azColName)
{
    sqlite3 *DB;
    sqlite3_open("Payroll.db", &DB);
    int i;
    fprintf(stderr, "%s: ", (const char *)data);

    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

bool Payroll::callReadDB(std::string query_)
{
    sqlite3_open("Payroll.db", &DB);
    exit_ = sqlite3_exec(DB, query_.c_str(), readDB, NULL, NULL);
    if (exit_ != SQLITE_OK)
    {
        return false;
    }
    else
        return true;
}

bool Payroll::updateDB(std::string sql_)
{
    sqlite3 *DB;
    exit_ = sqlite3_open("Payroll.db", &DB);
    exit_ = sqlite3_exec(DB, sql_.c_str(), NULL, 0, &messaggeError_);
    if (exit_ != SQLITE_OK)
    {
        std::cerr << "Error Insert" << messaggeError_ << std::endl;
        reset();
        return false;
    }
    else
    {
        reset();
        return true;
    }
}

bool Payroll::deleteDB(std::string sql_)
{
    sqlite3 *DB;
    exit_ = sqlite3_open("Payroll.db", &DB);
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

void Payroll::setName(std::string name)
{
    name_ = name;
}

void Payroll::setRole(Role roleNumber)
{
    switch (roleNumber)
    {
    case Role::ENGINEER:
        role_ = "ENGINEER";
        break;
    case Role::MECHANIC:
        role_ = "MECHANIC";
        break;
    case Role::TECHNICIAN:
        role_ = "TECHNICIAN";
        break;
    case Role::INTERN:
        role_ = "INTERN";
        break;

    default:
        std::cout << "INVALID ANSWER!\n";
        break;
    }
}

void Payroll::setWorkedHours(double workedHours)
{
    workedHours_ = workedHours;
}

double Payroll::calculatePayroll(double workedHours)
{
    if (role_ == "ENGINEER")
    {
        payment_ = workedHours * 60;
    }
    else if (role_ == "MECHANIC")
    {
        payment_ = workedHours * 45;
    }
    else if (role_ == "TECHNICIAN")
    {
        payment_ = workedHours * 28.95;
    }
    else
    {
        payment_ = workedHours * 12.5;
    }
    return payment_;
}

std::string Payroll::createInsertSqlString(std::string name, std::string role, double workedHours, double payment)
{
    return ("INSERT INTO PAYROLL (NAME, ROLE, WORKED_HOURS, PAYMENT) VALUES('" + name + "', '" + role + "', " + std::to_string(workedHours) + ", " + std::to_string(payment) + ");");
}

std::string Payroll::getName()
{
    return name_;
}

double Payroll::getWorkedHours()
{
    return workedHours_;
}

std::string Payroll::getRole()
{
    return role_;
}

void Payroll::reset()
{
    name_ = "";
    role_ = "";
    workedHours_ = 0;
    payment_ = 0;
}
