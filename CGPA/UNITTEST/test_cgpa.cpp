#include "gtest/gtest.h"
#include "../INCLUDE/cgpa.hpp"

class test_cgpa : public CGPA, public ::testing::Test
{
public:
    CGPA dut_;
};

TEST_F(test_cgpa, reset)
{
    dut_.setStudentName("Robson");
    dut_.setNumberOfSubjects(3);
    dut_.setGrades(8);
    dut_.setGrades(7.5);
    dut_.setGrades(8.5);
    dut_.calculateAverage();

    EXPECT_EQ(dut_.getAverage(), 8);
    dut_.reset();

    EXPECT_EQ(dut_.getNumberOfSubjects(), 0);
}

TEST_F(test_cgpa, testName)
{
    dut_.reset();
    dut_.setStudentName("Denilson");
    EXPECT_EQ(dut_.getStudentName(), "Denilson");
}

TEST_F(test_cgpa, getNumberOfSubjects)
{
    dut_.reset();
    dut_.setNumberOfSubjects(8);
    EXPECT_EQ(dut_.getNumberOfSubjects(), 8);
}

TEST_F(test_cgpa, getAverage)
{
    dut_.reset();
    dut_.setNumberOfSubjects(8);
    EXPECT_EQ(dut_.getNumberOfSubjects(), 8);
    dut_.setGrades(7);
    dut_.setGrades(7.5);
    dut_.setGrades(6.5);
    dut_.setGrades(6);
    dut_.setGrades(8);
    dut_.setGrades(7);
    dut_.setGrades(9);
    dut_.setGrades(8.5);

    dut_.calculateAverage();
    EXPECT_EQ(dut_.getAverage(), 7.4375);

    dut_.reset();
    dut_.setNumberOfSubjects(6);
    EXPECT_EQ(dut_.getNumberOfSubjects(), 6);
    dut_.setGrades(7);
    dut_.setGrades(7.5);
    dut_.setGrades(6.5);
    dut_.setGrades(6);
    dut_.setGrades(8);
    dut_.setGrades(7);

    dut_.calculateAverage();
    ASSERT_EQ(dut_.getAverage(), 7);
}

TEST_F(test_cgpa, aboveZero)
{
    dut_.reset();
    dut_.setNumberOfSubjects(-1);
    EXPECT_EQ(dut_.getNumberOfSubjects(), 0);
}