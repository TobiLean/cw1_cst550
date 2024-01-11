#ifndef _PERSON_H_
#define _PERSON_H_

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