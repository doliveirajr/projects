#include "../INCLUDE/rPsGame.hpp"

int rPsGame::pickWinner(std::string playerOne, std::string playerTwo)
{
    if (playerOne == playerTwo)
    {
        return 0;
    }

    if (playerOne == "Scissor" && playerTwo == "Paper")
    {
        return 1;
    }

    if (playerOne == "Paper" && playerTwo == "Rock")
    {
        return 1;
    }

    if (playerOne == "Rock" && playerTwo == "Scissor")
    {
        return 1;
    }
    else
        return -1;
}

void rPsGame::reset()
{
    setPlayerOne("");
    setPlayerTwo("");
}