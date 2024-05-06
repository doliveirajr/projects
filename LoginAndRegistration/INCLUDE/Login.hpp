#ifndef LOGIN_HPP
#define LOGIN_HPP
#include "./LoginAndRegistration.hpp"
#include <iostream>

class Login : public LoginAndRegistration
{
private:
    std::string choice_{""};
public:
    Login() : LoginAndRegistration(Option::LOGIN)
    {
        setChoice("Login");
    }
    void setChoice(std::string choice){ choice_ = choice;};
};

#endif