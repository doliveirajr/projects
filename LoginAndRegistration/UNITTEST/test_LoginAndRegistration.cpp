#include "../INCLUDE/LoginAndRegistration.hpp"
#include "gtest/gtest.h"
#include "../INCLUDE/Factory.hpp"

class test_LoginAndRegistration : public LoginAndRegistration, public ::testing::Test
{
private:
public:
};

TEST_F(test_LoginAndRegistration, TestIfSetOption)
{

    // LoginAndRegistration dut_;
    // dut_.setChoice("Alalalala");
    // ASSERT_EQ(dut_.getChoice(), "Alalalala");
}