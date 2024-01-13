#ifndef _DATE_H_
#define _DATE_H_

class Date
{
private:
    int day, month, year;

public:

    Date();
    Date(int day, int month, int year);

    int getDay();
    int getMonth();
    int getYear();
};

#endif