#include "../INCLUDE/CassinoGame.hpp"

int CassinoGame::selectDifficult(DifficultLevel level)
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
        break;
    }
    return 0;
}

int CassinoGame::getPlayersChoice()
{
    return choice_;
}

int CassinoGame::getCassinoRandomNumber()
{
    return randomNumber_;
}

std::string CassinoGame::getWinner(short int playerChoice, short int cassinoRandomNumber)
{
    if (playerChoice == cassinoRandomNumber)
    {
        return "Player Wins!";
    }
    return "Cassino Wins!";
}