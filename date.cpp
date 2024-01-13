#include "date.h"

Date::Date()
{
    this->day = 9;
    this->month = 1;
    this->year = 2003;
};
Date::Date(int d, int m, int y)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDay(){
    return day;
}

int Date::getMonth(){
    return month;
}

int Date::getYear(){
    return year;
}
