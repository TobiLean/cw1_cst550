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

    // Date::fullDate = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

int Date::getNumberOfDays(Date d1, Date d2)
{
    Date greater;
    Date lesser;
    if (d2 > d1)
    {
        greater = d2;
        lesser = d1;
    }
    else if (d1 > d2)
    {
        greater = d1;
        lesser = d2;
    }
    int total = (greater.getDay() - lesser.getDay()) + ((greater.getMonth() - lesser.getMonth())*30) + ((greater.getYear() - lesser.getYear())*365);

    return total;
}

// std::string Date::getFullDate() const
// {
//     return fullDate;
// }

bool operator<(const Date &lhs, const Date &rhs)
{
    if (lhs.year < rhs.year)
    {
        return true;
    }
    else if (lhs.year == rhs.year && lhs.month < rhs.month)
    {
        return true;
    }
    else if (
        lhs.year == rhs.year && lhs.month == rhs.month && lhs.day < rhs.day)
    {
        return true;
    }

    return false;
};

bool operator>(const Date &lhs, const Date &rhs)
{
    if (lhs.year > rhs.year)
    {
        return true;
    }
    else if (lhs.year == rhs.year && lhs.month > rhs.month)
    {
        return true;
    }
    else if (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day > rhs.day)
    {
        return true;
    }

    return false;
};

bool operator==(const Date &lhs, const Date &rhs)
{
    if (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day)
    {
        return true;
    }

    return false;
};

std::ostream& operator<<(std::ostream& out, const Date& date)
{
    out << std::to_string(date.getDay()) + "/" + std::to_string(date.getMonth()) + "/" + std::to_string(date.getYear());
    return out;
};

