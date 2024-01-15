#include "person.h"
#include <iostream>

/*
    function to get private field name
    @return a string of the name field
*/
const std::string Person::getName()
{
    return Person::name;
}

/*
    function to set private field name
    @param string name
*/
void Person::setName(std::string name)
{
    Person::name = name;
}

/*
    function to get private field address
    @return a string of the address field
*/
const std::string Person::getAddress()
{
    return Person::address;
}

/*
    function to set private field address
    @param string address
*/
void Person::setAddress(std::string address)
{
    Person::address = address;
}

/*
    function to get private field email
    @return a string of the email field
*/
const std::string Person::getEmail()
{
    return Person::email;
}

/*
    function to set private field email
    @param string email
*/
void Person::setEmail(std::string email)
{
    Person::email = email;
}