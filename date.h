#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>

/// Date class to use for ticket and schedule type objects

class Date
{
public:
    int month;
    int day;
    int year;

    Date()
    {
        month = 0;
        day = 0;
        year = 0;
    }
};

#endif // DATE_H_INCLUDED
