#ifndef REGISTRATION_HPP
#define REGISTRATION_HPP
#include "./LoginAndRegistration.hpp"
#include <iostream>

class Registration : public LoginAndRegistration
{
private:
    std::string choice_{""};
public:
    Registration() : LoginAndRegistration(Option::REGISTRATION)
    {
        setChoice("Registration");
    }
    void setChoice(std::string choice);
};

#endif