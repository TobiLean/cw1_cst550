#ifndef _DATE_H_
#define _DATE_H_

#include <string>

class Date
{
private:
    int day, month, year;
    std::string fullDate;

public:

    //Default constructor for the Date Abstract Data Type
    Date();
    //Constructor for the Date ADT
    Date(int day, int month, int year);

    //Declaring functions
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getNumberOfDays(Date d1, Date d2);

    //declaring overloading operators for Date Class
    friend bool operator<(const Date& lhs, const Date& rhs);
    friend bool operator>(const Date& lhs, const Date& rhs);
    friend bool operator==(const Date& lhs, const Date& rhs);
};

//overloadin cout << left shif operator for Date Class
std::ostream& operator<<(std::ostream& out, const Date& date);

#endif