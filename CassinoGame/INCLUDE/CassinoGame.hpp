#ifndef CASSINOGAME_HPP
#define CASSINOGAME_HPP
#include <iostream>
#include <ctime>

enum class DifficultLevel
{
    INVALID = -1,
    EASY = 1,
    NORMAL,
    HARD,
    VERY_HARD
};

class CassinoGame
{
private:
    short int choice_{0};
    short int randomNumber_{0};

public:
    CassinoGame() { srand(std::time(nullptr)); };
    int selectDifficult(DifficultLevel level);
    void setPlayersChoice(short int choice) { choice_ = choice; };
    void setCassinoRandomNumber(short int difficult) { difficult > 0 ? randomNumber_ = (std::rand() % difficult)+1 : false; }

    int getPlayersChoice();
    int getCassinoRandomNumber();
    std::string getWinner(short int playerChoice, short int cassinoRandomNumber);
};

#endif