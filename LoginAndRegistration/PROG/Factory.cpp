#include "../INCLUDE/Factory.hpp"

LoginAndRegistration* Factory::selectOption(Option option)
{
    switch (option)
    {
    case Option::LOGIN:
        return new Login;
        break;

    case Option::REGISTRATION:
        return new Registration;
        break;

    default:
        break;
    }
};