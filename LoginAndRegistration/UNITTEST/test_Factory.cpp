#include "gtest/gtest.h"
#include "../INCLUDE/Factory.hpp"

class test_Factory : public Factory, public ::testing::TestWithParam<Option>
{
protected:
    Factory dut_;
    std::string MyChoice(Option opt)
    {
        switch (opt)
        {
        case Option::LOGIN:
            return "Login";
            break;

        case Option::REGISTRATION:
            return "Registration";
            break;

        default:
            break;
        }
        return "NULL";
    }

public:
};

TEST_P(test_Factory, ChecksIfIsSelectedFactory)
{
    const Option &params = GetParam();
    auto actual = dut_.selectOption(params);
    auto expected = MyChoice(params);
    EXPECT_EQ(actual->getChoice(), expected);
}

INSTANTIATE_TEST_SUITE_P(
    ParameterizedOptionTest,
    test_Factory,
    ::testing::Values(
        Option::LOGIN,
        Option::REGISTRATION));