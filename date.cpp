#include "date.h"
#include <string>

Date::Date()
{
    this->day = 9;
    this->month = 1;
    this->year = 2003;
};
Date::Date(int d, int m, int y)
{
    this->day = d;
    this->month = m;
    this->year = y;
    
    Date::fullDate = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

std::string Date::getFullDate()
{
    return fullDate;
}
