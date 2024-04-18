#include "gtest/gtest.h"
#include "../INCLUDE/rPsGame.hpp"

class test_rPsGame : public rPsGame, public ::testing::Test
{
public:
    rPsGame dut_;
};

TEST_F(test_rPsGame, TestIfCorrectChoiceIsSet)
{
    dut_.setPlayerOne("Scissor");
    dut_.setPlayerTwo("Paper");

    EXPECT_EQ(dut_.getPlayerOneChoice(), "Scissor");
    EXPECT_EQ(dut_.getPlayerTwoChoice(), "Paper");

    dut_.setPlayerOne("Paper");
    dut_.setPlayerTwo("Rock");

    EXPECT_EQ(dut_.getPlayerOneChoice(), "Paper");
    EXPECT_EQ(dut_.getPlayerTwoChoice(), "Rock");
}

TEST_F(test_rPsGame, TestWhoWins)
{
    dut_.reset();
    dut_.setPlayerOne("Scissor");
    dut_.setPlayerTwo("Paper");
    ASSERT_EQ(dut_.pickWinner(dut_.getPlayerOneChoice(), dut_.getPlayerTwoChoice()), 1);
    
    dut_.reset();
    dut_.setPlayerOne("Paper");
    dut_.setPlayerTwo("Paper");
    ASSERT_EQ(dut_.pickWinner(dut_.getPlayerOneChoice(), dut_.getPlayerTwoChoice()), 0);
    
    dut_.reset();
    dut_.setPlayerOne("Rock");
    dut_.setPlayerTwo("Paper");
    ASSERT_EQ(dut_.pickWinner(dut_.getPlayerOneChoice(), dut_.getPlayerTwoChoice()), -1);
    
    dut_.reset();
    dut_.setPlayerOne("Paper");
    dut_.setPlayerTwo("Rock");
    ASSERT_EQ(dut_.pickWinner(dut_.getPlayerOneChoice(), dut_.getPlayerTwoChoice()), 1);
    
    dut_.reset();
    dut_.setPlayerOne("Rock");
    dut_.setPlayerTwo("Rock");
    ASSERT_EQ(dut_.pickWinner(dut_.getPlayerOneChoice(), dut_.getPlayerTwoChoice()), 0);
    
    dut_.reset();
    dut_.setPlayerOne("Paper");
    dut_.setPlayerTwo("Scissor");
    ASSERT_EQ(dut_.pickWinner(dut_.getPlayerOneChoice(), dut_.getPlayerTwoChoice()), -1);
    
    dut_.reset();
    dut_.setPlayerOne("Rock");
    dut_.setPlayerTwo("Scissor");
    ASSERT_EQ(dut_.pickWinner(dut_.getPlayerOneChoice(), dut_.getPlayerTwoChoice()), 1);
    
    dut_.reset();
    dut_.setPlayerOne("Scissor");
    dut_.setPlayerTwo("Scissor");
    ASSERT_EQ(dut_.pickWinner(dut_.getPlayerOneChoice(), dut_.getPlayerTwoChoice()), 0);
    
    dut_.reset();
    dut_.setPlayerOne("Scissor");
    dut_.setPlayerTwo("Rock");
    ASSERT_EQ(dut_.pickWinner(dut_.getPlayerOneChoice(), dut_.getPlayerTwoChoice()), -1);
}

TEST_F(test_rPsGame, TestIfChoicesReset)
{
    dut_.setPlayerOne("Scissor");
    dut_.setPlayerTwo("Paper");

    EXPECT_EQ(dut_.getPlayerOneChoice(), "Scissor");
    EXPECT_EQ(dut_.getPlayerTwoChoice(), "Paper");

    dut_.reset();
    EXPECT_EQ(dut_.getPlayerOneChoice(), "");
    EXPECT_EQ(dut_.getPlayerTwoChoice(), "");

    dut_.setPlayerOne("Paper");
    dut_.setPlayerTwo("Rock");

    EXPECT_EQ(dut_.getPlayerOneChoice(), "Paper");
    EXPECT_EQ(dut_.getPlayerTwoChoice(), "Rock");
    
    dut_.reset();
    EXPECT_EQ(dut_.getPlayerOneChoice(), "");
    EXPECT_EQ(dut_.getPlayerTwoChoice(), "");
}