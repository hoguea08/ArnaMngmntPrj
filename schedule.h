#ifndef SCHEDULE_H_INCLUDED
#define SCHEDULE_H_INCLUDED

#include "date.h"
#include "time.h"
#include "ticket.h"
#include <iostream>
#include <vector>
#include <fstream>

/// Schedule class

class Schedule
{
private:
    Date date;
    Time time;
    std::string event;

public:
    Schedule()
    {
        event = " ";
    }

    int getDateDay() {return date.day;}
	void setDateDay(int d) {date.day = d;}

	int getDateMonth() {return date.month;}
	void setDateMonth(int m) {date.month = m;}

	int getDateYear() {return date.year;}
	void setDateYear(int y) {date.year = y;}

	int getTimeHour() {return time.hour;}
	void setTimeHour(int h) {time.hour = h;}

	int getTimeMinute() {return time.minute;}
	void setTimeMinute(int m) {time.minute = m;}

	std::string getEvent() {return event;}
	void setEvent(std::string e) {event = e;}

    void readSchedData(std::fstream&);
    friend bool operator== ( const Schedule&, const Schedule&);
};

    void scheduleOptions(std::vector <Schedule>&, int&, std::vector <Ticket>&, int&, Bank&);
	void printEventInfo(std::vector <Schedule>&, int&);
	void createNewEvent(std::vector <Schedule>&, int&, std::vector <Ticket>&, int&);
	void changeEvent(std::vector <Schedule>&, int&, std::vector <Ticket>&, int&);
	void cancelEvent(std::vector <Schedule>&, int&, Bank&, std::vector <Ticket>&, int&);

#endif // SCHEDULE_H_INCLUDED
