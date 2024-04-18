#ifndef RPSGAME_HPP
#define RPSGAME_HPP
#include <iostream>

class rPsGame
{
private:
    std::string playerOneChoice_ = "";
    std::string playerTwoChoice_ = "";

public:
    rPsGame() { reset(); }
    void setPlayerOne(std::string choice) { playerOneChoice_ = choice; };
    std::string getPlayerOneChoice() { return playerOneChoice_; };

    void setPlayerTwo(std::string choice) { playerTwoChoice_ = choice; };
    std::string getPlayerTwoChoice() { return playerTwoChoice_; };

    int pickWinner(std::string playerOne, std::string playerTwo);
    void reset();
};

#endif