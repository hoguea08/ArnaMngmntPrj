#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>

/// Time class to use for ticket and schedule type objects

class Time
{
public:

    int hour;
    int minute;

    Time()
    {
        hour = 0;
        minute = 0;
    }

};

#endif // TIME_H_INCLUDED
