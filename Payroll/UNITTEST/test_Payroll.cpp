#include <gtest/gtest.h>
#include "../INCLUDE/Payroll.hpp"

class test_Payroll : public ::testing::Test
{
protected:
    virtual void SetUp() override
    {
        ::testing::Test::SetUp();
        dut_ = new Payroll();
    }

    virtual void TearDown() override
    {
        delete dut_;
        ::testing::Test::TearDown();
    }

    Payroll *dut_;
};

TEST_F(test_Payroll, TestIfCanCreateDB)
{
    auto createSQL = ("CREATE TABLE IF NOT EXISTS PAYROLL("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "NAME TEXT NOT NULL, "
                      "ROLE TEXT NOT NULL, "
                      "WORKED_HOURS DOUBLE NOT NULL, "
                      "PAYMENT DOUBLE NOT NULL );");

    ASSERT_TRUE(dut_->createDB(createSQL));
}

TEST_F(test_Payroll, TestIfCanSetName)
{

    dut_->reset();
    ASSERT_EQ(dut_->getName(), "");

    dut_->setName("Augustin Rossi");
    ASSERT_EQ(dut_->getName(), "Augustin Rossi");

    dut_->reset();

    dut_->setName("Arthur Antunes Coimbra");
    ASSERT_EQ(dut_->getName(), "Arthur Antunes Coimbra");

    dut_->reset();

    dut_->setName("Leovegildo Lins Gama Júnior");
    ASSERT_EQ(dut_->getName(), "Leovegildo Lins Gama Júnior");

    dut_->reset();

    dut_->setName("Edson Arantes do Nascimento");
    ASSERT_EQ(dut_->getName(), "Edson Arantes do Nascimento");

    dut_->reset();
    ASSERT_EQ(dut_->getName(), "");
}

TEST_F(test_Payroll, TestIfCanSetRole)
{
    dut_->reset();
    ASSERT_EQ(dut_->getRole(), "");

    dut_->setRole(Role::ENGINEER);
    ASSERT_EQ(dut_->getRole(), "ENGINEER");

    dut_->reset();

    dut_->setRole(Role::MECHANIC);
    ASSERT_EQ(dut_->getRole(), "MECHANIC");

    dut_->reset();

    dut_->setRole(Role::TECHNICIAN);
    ASSERT_EQ(dut_->getRole(), "TECHNICIAN");

    dut_->reset();

    dut_->setRole(Role::INTERN);
    ASSERT_EQ(dut_->getRole(), "INTERN");

    dut_->reset();
    ASSERT_EQ(dut_->getRole(), "");
}

TEST_F(test_Payroll, TestIfCanCreateInsertCommand)
{
    dut_->reset();
    ASSERT_EQ(dut_->getName(), "");
    ASSERT_EQ(dut_->getRole(), "");
    ASSERT_EQ(dut_->getWorkedHours(), 0);

    dut_->setName("Bruce Banner");
    auto name = dut_->getName();
    dut_->setRole(Role::ENGINEER);
    auto role = dut_->getRole();
    dut_->setWorkedHours(200);
    auto workedHours = dut_->getWorkedHours();
    auto payment = dut_->calculatePayroll(workedHours);
    auto expected = ("INSERT INTO PAYROLL (NAME, ROLE, WORKED_HOURS, PAYMENT) VALUES('Bruce Banner', 'ENGINEER', 200.000000, 12000.000000);");
    ASSERT_EQ(dut_->createInsertSqlString(name, role, workedHours, payment), expected);

    dut_->reset();
    ASSERT_EQ(dut_->getName(), "");
    ASSERT_EQ(dut_->getRole(), "");
    ASSERT_EQ(dut_->getWorkedHours(), 0);

    dut_->setName("Al Pacino");
    name = dut_->getName();
    dut_->setRole(Role::MECHANIC);
    role = dut_->getRole();
    dut_->setWorkedHours(200);
    workedHours = dut_->getWorkedHours();
    payment = dut_->calculatePayroll(workedHours);
    expected = ("INSERT INTO PAYROLL (NAME, ROLE, WORKED_HOURS, PAYMENT) VALUES('Al Pacino', 'MECHANIC', 200.000000, 9000.000000);");
    ASSERT_EQ(dut_->createInsertSqlString(name, role, workedHours, payment), expected);
}

TEST_F(test_Payroll, TestIfCanCallReadDb)
{
    dut_->reset();
    auto sql = "SELECT * FROM PAYROLL;";
    ASSERT_TRUE(dut_->callReadDB(sql));

    sql = "SELECT NAME as Nome, ID as Nº, PAYMENT as Salário FROM PAYROLL WHERE ID > 4 AND PAYMENT > 5096;";
    ASSERT_TRUE(dut_->callReadDB(sql));
}

TEST_F(test_Payroll, TestIfCanInsertItem)
{
    auto createSQL = ("CREATE TABLE IF NOT EXISTS PAYROLL("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "NAME TEXT NOT NULL, "
                      "ROLE TEXT NOT NULL, "
                      "WORKED_HOURS DOUBLE NOT NULL, "
                      "PAYMENT DOUBLE NOT NULL );");

    dut_->createDB(createSQL);

    dut_->setName("Louro José");
    dut_->setRole(Role::INTERN);
    dut_->setWorkedHours(120.0);
    ASSERT_EQ(dut_->getName(), "Louro José");
    ASSERT_EQ(dut_->getRole(), "INTERN");
    ASSERT_EQ(dut_->getWorkedHours(), 120.0);

    auto workedHours = dut_->getWorkedHours();
    ASSERT_EQ(dut_->calculatePayroll(workedHours), 1500.0);
    auto insert = ("INSERT INTO PAYROLL (NAME, ROLE, WORKED_HOURS, PAYMENT) VALUES('" + dut_->getName() + "', '" + dut_->getRole() + "', " + std::to_string(workedHours) + ", " + std::to_string(dut_->calculatePayroll(workedHours)) + ");");

    ASSERT_TRUE(dut_->updateDB(insert));
    ASSERT_EQ(dut_->getName(), "");
    ASSERT_EQ(dut_->getRole(), "");
    ASSERT_EQ(dut_->getWorkedHours(), 0);

    dut_->setName("Casimiro Miguel");
    dut_->setRole(Role::ENGINEER);
    dut_->setWorkedHours(176.0);
    ASSERT_EQ(dut_->getName(), "Casimiro Miguel");
    ASSERT_EQ(dut_->getRole(), "ENGINEER");
    ASSERT_EQ(dut_->getWorkedHours(), 176.0);

    workedHours = dut_->getWorkedHours();
    ASSERT_EQ(dut_->calculatePayroll(workedHours), 10560.0);
    insert = dut_->createInsertSqlString(dut_->getName(), dut_->getRole(), dut_->getWorkedHours(), dut_->calculatePayroll(workedHours));

    ASSERT_TRUE(dut_->updateDB(insert));
    ASSERT_EQ(dut_->getName(), "");
    ASSERT_EQ(dut_->getRole(), "");
    ASSERT_EQ(dut_->getWorkedHours(), 0);

    dut_->setName("Usain Bolt");
    dut_->setRole(Role::MECHANIC);
    dut_->setWorkedHours(176.0);
    ASSERT_EQ(dut_->getName(), "Usain Bolt");
    ASSERT_EQ(dut_->getRole(), "MECHANIC");
    ASSERT_EQ(dut_->getWorkedHours(), 176.0);

    workedHours = dut_->getWorkedHours();
    ASSERT_EQ(dut_->calculatePayroll(workedHours), 7920.0);
    insert = dut_->createInsertSqlString(dut_->getName(), dut_->getRole(), dut_->getWorkedHours(), dut_->calculatePayroll(workedHours));

    ASSERT_TRUE(dut_->updateDB(insert));
    ASSERT_EQ(dut_->getName(), "");
    ASSERT_EQ(dut_->getRole(), "");
    ASSERT_EQ(dut_->getWorkedHours(), 0);

    dut_->setName("Michael Phelps");
    dut_->setRole(Role::TECHNICIAN);
    dut_->setWorkedHours(176.0);
    ASSERT_EQ(dut_->getName(), "Michael Phelps");
    ASSERT_EQ(dut_->getRole(), "TECHNICIAN");
    ASSERT_EQ(dut_->getWorkedHours(), 176.0);

    workedHours = dut_->getWorkedHours();
    ASSERT_EQ(dut_->calculatePayroll(workedHours), 5095.2);
    insert = dut_->createInsertSqlString(dut_->getName(), dut_->getRole(), dut_->getWorkedHours(), dut_->calculatePayroll(workedHours));

    ASSERT_TRUE(dut_->updateDB(insert));
    ASSERT_EQ(dut_->getName(), "");
    ASSERT_EQ(dut_->getRole(), "");
    ASSERT_EQ(dut_->getWorkedHours(), 0);
}

TEST_F(test_Payroll, TestIfCanDeleteFromDb)
{
    dut_->reset();
    auto sql = "DELETE FROM PAYROLL";
    ASSERT_TRUE(dut_->deleteDB(sql));

    dut_->reset();
    sql = "DELETE FROM PAYROL";
    ASSERT_FALSE(dut_->deleteDB(sql));
}