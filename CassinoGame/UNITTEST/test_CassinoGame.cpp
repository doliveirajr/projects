#include "gtest/gtest.h"
#include "../INCLUDE/CassinoGame.hpp"

class test_CassinoGame : public CassinoGame, public ::testing::TestWithParam<DifficultLevel>
{
public:
    CassinoGame dut_;

protected:
    int myDifficult(DifficultLevel level)
    {
        switch (level)
        {
        case DifficultLevel::EASY:
            return 2;
            break;

        case DifficultLevel::NORMAL:
            return 4;
            break;

        case DifficultLevel::HARD:
            return 8;
            break;

        case DifficultLevel::VERY_HARD:
            return 16;
            break;

        default:
            return 0;
        }
    }
};

TEST_P(test_CassinoGame, TestIfDifficultIsSelectedCorrect)
{
    const DifficultLevel &params = GetParam();
    auto actual = dut_.selectDifficult(params);
    auto expected = myDifficult(params);
    ASSERT_EQ(actual, expected);
}

TEST_F(test_CassinoGame, TestIfPlayersChoiceIsSet)
{
    dut_.setPlayersChoice(5);
    ASSERT_EQ(dut_.getPlayersChoice(), 5);

    dut_.setPlayersChoice(15);
    ASSERT_EQ(dut_.getPlayersChoice(), 15);

    dut_.setPlayersChoice(25);
    ASSERT_EQ(dut_.getPlayersChoice(), 25);

    dut_.setPlayersChoice(35);
    ASSERT_EQ(dut_.getPlayersChoice(), 35);

    dut_.setPlayersChoice(75);
    ASSERT_EQ(dut_.getPlayersChoice(), 75);
}

TEST_F(test_CassinoGame, TestIfCassinoNumberIsSet)
{
    auto difficult = dut_.selectDifficult(DifficultLevel::EASY);
    dut_.setCassinoRandomNumber(difficult);
    dut_.setPlayersChoice(3);
    ASSERT_TRUE(dut_.getCassinoRandomNumber());
}

TEST_F(test_CassinoGame, TestWhoWinWhenEasy)
{
    auto difficult = dut_.selectDifficult(DifficultLevel::EASY);
    dut_.setPlayersChoice(1);
    auto playerChoice = dut_.getPlayersChoice();
    dut_.setCassinoRandomNumber(difficult);

    if (playerChoice == dut_.getCassinoRandomNumber())
    {
        EXPECT_EQ(dut_.getWinner(playerChoice, dut_.getCassinoRandomNumber()), "Player Wins!");
    }
    else
    {
        EXPECT_EQ(dut_.getWinner(playerChoice, dut_.getCassinoRandomNumber()), "Cassino Wins!");
    }
}

TEST_F(test_CassinoGame, TestWhoWinWhenNormal)
{
    auto difficult = dut_.selectDifficult(DifficultLevel::NORMAL);
    dut_.setPlayersChoice(1);
    auto playerChoice = dut_.getPlayersChoice();
    dut_.setCassinoRandomNumber(difficult);

    if (playerChoice == dut_.getCassinoRandomNumber())
    {
        EXPECT_EQ(dut_.getWinner(playerChoice, dut_.getCassinoRandomNumber()), "Player Wins!");
    }
    else
    {
        EXPECT_EQ(dut_.getWinner(playerChoice, dut_.getCassinoRandomNumber()), "Cassino Wins!");
    }
}

TEST_F(test_CassinoGame, TestWhoWinWhenHard)
{
    auto difficult = dut_.selectDifficult(DifficultLevel::HARD);
    dut_.setPlayersChoice(1);
    auto playerChoice = dut_.getPlayersChoice();
    dut_.setCassinoRandomNumber(difficult);

    if (playerChoice == dut_.getCassinoRandomNumber())
    {
        EXPECT_EQ(dut_.getWinner(playerChoice, dut_.getCassinoRandomNumber()), "Player Wins!");
    }
    else
    {
        EXPECT_EQ(dut_.getWinner(playerChoice, dut_.getCassinoRandomNumber()), "Cassino Wins!");
    }
}

TEST_F(test_CassinoGame, TestWhoWinWhenVeryHard)
{
    auto difficult = dut_.selectDifficult(DifficultLevel::VERY_HARD);
    dut_.setPlayersChoice(1);
    auto playerChoice = dut_.getPlayersChoice();
    dut_.setCassinoRandomNumber(difficult);

    if (playerChoice == dut_.getCassinoRandomNumber())
    {
        EXPECT_EQ(dut_.getWinner(playerChoice, dut_.getCassinoRandomNumber()), "Player Wins!");
    }
    else
    {
        EXPECT_EQ(dut_.getWinner(playerChoice, dut_.getCassinoRandomNumber()), "Cassino Wins!");
    }
}

INSTANTIATE_TEST_CASE_P(
    ParameterizedDifficultTest,
    test_CassinoGame,
    ::testing::Values(
        DifficultLevel::EASY,
        DifficultLevel::NORMAL,
        DifficultLevel::HARD,
        DifficultLevel::VERY_HARD));