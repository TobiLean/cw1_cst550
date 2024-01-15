#include "person.h"
#include <iostream>

//declaring function to get name from child classes
const std::string Person::getName()
{
    return Person::name;
}

//declaring function to set name for child classes
void Person::setName(std::string name)
{
    Person::name = name;
}

//declaring function to get address from child classes
const std::string Person::getAddress()
{
    return Person::address;
}

//declaring function to set address from child classes
void Person::setAddress(std::string address)
{
    Person::address = address;
}

//declaring function to get name from child classes
const std::string Person::getEmail()
{
    return Person::email;
}

void Person::setEmail(std::string email)
{
    Person::email = email;
}