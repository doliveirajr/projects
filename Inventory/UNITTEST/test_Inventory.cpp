#include "../INCLUDE/Inventory.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>


class test_Inventory : public ::testing::Test
{
public:
    // test_Inventory() : ::testing::Test(), dut_(NULL)
    // {
    // }

protected:
    virtual void SetUp() override
    {
        ::testing::Test::SetUp();
        dut_ = new Inventory();
    }

    virtual void TearDown() override
    {
        delete dut_;
        ::testing::Test::TearDown();
        system("rm -rf Inventory.db");
    }

    Inventory *dut_;
};

TEST_F(test_Inventory, TestIfTableAreCreated)
{
    auto query = ("CREATE TABLE INVENTORY("
                  "ID INT PRIMARY KEY	 NOT NULL, "
                  "NAME		 TEXT NOT NULL, "
                  "PRICE		 REAL	 NOT NULL, "
                  "QUANTITY		 INT	 NOT NULL );");

    EXPECT_TRUE(dut_->createDB(query));
}

TEST_F(test_Inventory, TestIfCanInsertNewItemToTable)
{
    auto query = ("CREATE TABLE INVENTORY("
                  "ID INT PRIMARY KEY	 NOT NULL, "
                  "NAME		 TEXT NOT NULL, "
                  "PRICE		 REAL	 NOT NULL, "
                  "QUANTITY		 INT	 NOT NULL );");

    dut_->createDB(query);

    auto sql = ("INSERT INTO INVENTORY VALUES(1, 'TV', 2455.0, 48);"
                "INSERT INTO INVENTORY VALUES(2, 'PS5', 2000.5, 25);"
                "INSERT INTO INVENTORY VALUES(3, 'NOTEBOOK', 2950.0, 20);");

    ASSERT_TRUE(dut_->updateDB(sql));
}

TEST_F(test_Inventory, TestIfCallsReadDB) {
    auto query = ("CREATE TABLE INVENTORY("
                  "ID INT PRIMARY KEY	 NOT NULL, "
                  "NAME		 TEXT NOT NULL, "
                  "PRICE		 REAL	 NOT NULL, "
                  "QUANTITY		 INT	 NOT NULL );");

    dut_->createDB(query);

    auto sql = ("INSERT INTO INVENTORY VALUES(1, 'TV', 2455.0, 48);"
                "INSERT INTO INVENTORY VALUES(2, 'PS5', 2000.5, 25);"
                "INSERT INTO INVENTORY VALUES(3, 'NOTEBOOK', 2950.0, 20);");

    dut_->updateDB(sql);

    auto read = "SELECT * FROM INVENTORY WHERE ID = 2";
    ASSERT_TRUE(dut_->callReadDB(read));

    sql = "INSERT INTO INVENTORY VALUES(4, 'MICROWAVE', 2805.0, 85);";
    dut_->updateDB(sql);

    read = "SELECT * FROM INVENTORY WHERE PRICE > 2500";

    ASSERT_TRUE(dut_->callReadDB(read));
}

TEST_F(test_Inventory, TestIfCanDeleItemFromTable) {
    auto query = ("CREATE TABLE INVENTORY("
                  "ID INT PRIMARY KEY	 NOT NULL, "
                  "NAME		 TEXT NOT NULL, "
                  "PRICE		 REAL	 NOT NULL, "
                  "QUANTITY		 INT	 NOT NULL );");

    dut_->createDB(query);

    auto sql = ("INSERT INTO INVENTORY VALUES(1, 'TV', 2455.0, 48);"
                "INSERT INTO INVENTORY VALUES(2, 'PS5', 2000.5, 25);"
                "INSERT INTO INVENTORY VALUES(3, 'NOTEBOOK', 2950.0, 20);");

    dut_->updateDB(sql);

    auto dlt = "DELETE FROM INVENTORY WHERE QUANTITY < 21;";

    ASSERT_TRUE(dut_->deleteDB(dlt));

    sql = "SELECT * FROM INVENTORY;";

    dlt = "DELETE FROM INVENTORY WHERE ID < 3;";

    ASSERT_TRUE(dut_->deleteDB(dlt));

    dut_->callReadDB(sql);
}