#ifndef LOGIN_AND_REGISTRATION_HPP
#define LOGIN_AND_REGISTRATION_HPP
#include "../INCLUDE/Factory.hpp"
#include <iostream>

enum class Option
{
    INVALID,
    LOGIN = 1,
    REGISTRATION
};

class LoginAndRegistration
{
private:
    Option option_{Option::INVALID};
    std::string choice_;
public:
    LoginAndRegistration() = default;
    LoginAndRegistration(Option option)
    {
        option_ = option;
    };

    void setChoice(std::string choice){choice_ = choice;};
    std::string getChoice(){ return choice_;};
};

#endif