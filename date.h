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

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    // std::string getFullDate() const;
    friend bool operator<(const Date& lhs, const Date& rhs);
    friend bool operator>(const Date& lhs, const Date& rhs);
    friend bool operator==(const Date& lhs, const Date& rhs);
};

std::ostream& operator<<(std::ostream& out, const Date& date);

#endif