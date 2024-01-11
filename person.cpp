#include "person.h"
#include <iostream>

const std::string Person::getName()
{
    return Person::name;
}

void Person::setName(std::string name)
{
    Person::name = name;
}

const std::string Person::getAddress()
{
    return Person::address;
}

void Person::setAddress(std::string address)
{
    Person::address = address;
}

const std::string Person::getEmail()
{
    return Person::email;
}

void Person::setEmail(std::string email)
{
    Person::email = email;
}