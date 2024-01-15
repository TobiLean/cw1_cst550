#ifndef _PERSON_H_
#define _PERSON_H_

/*
    person.h
    Author: M00885480
    Created: 12/01/2024
    Updated: 15/01/2024
*/

#include <string>

class Person
{
private:
    std::string name;
    std::string address;
    std::string email;

public:
    const std::string getName();

    void setName(std::string name);

    const std::string getAddress();

    void setAddress(std::string address);

    const std::string getEmail();

    void setEmail(std::string email);
};

#endif