#ifndef _DATE_H_
#define _DATE_H_

#include <string>

class Date
{
private:
    int day, month, year;
    std::string fullDate;

public:

    Date();
    Date(int day, int month, int year);

    int getDay();
    int getMonth();
    int getYear();
    std::string getFullDate();
};

#endif