#ifndef FACTORY_HPP
#define FACTORY_HPP
#include "./LoginAndRegistration.hpp"
#include "./Registration.hpp"
#include "./Login.hpp"

class Factory
{
private:
public:
    static LoginAndRegistration* selectOption(Option option);
};

#endif