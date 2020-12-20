
#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED

#include "date.h"
#include "time.h"
#include "bank.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

/// Ticket class

class Ticket
{
private:
    int section;
    int seat;
    double price;
    Date date;
    Time time;
    bool sold;
    std::string event;
    double sales;

public:
    Ticket()
    {
        section = 0;
        seat = 0;
        price = 0.0;
        sold = false;
        event = " ";
        sales = 0.0;
    }

    int getSection() {return section;}
	void setSection(int sec) {section = sec;}

	int getSeat() {return seat;}
	void setSeat(int s) {seat = s;}

	double getPrice() {return price;}
	void setPrice(double p) {price = p;}

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

	bool getSold() {return sold;}
	void setSold(bool s) {sold = s;}

	std::string getEvent() {return event;}
	void setEvent(std::string e) {event = e;}

	double getSales() {return sales;}
	void setSales(double s) {sales = s;}

    void readTicketData(std::fstream&, Bank&);
};

	void ticketOptions(std::vector <Ticket>&, Bank&, int&);
	void sellRefundOption(std::vector <Ticket>&, int&, Bank&);
	void displayAllTickets(std::vector <Ticket>&, int&);
	void displayAvailTickets(std::vector <Ticket>&, int&);
	void displayUnavailTickets(std::vector <Ticket>&, int&);
	void sellTicket(std::vector <Ticket>&, int&, Bank&);
	void refundTicket(std::vector <Ticket>&, int&, Bank&);
	void changeTicket(std::vector <Ticket>&, int&);
	void searchForTicket(std::vector <Ticket>&, int&);
	void createTickets(std::vector <Ticket>&, int&, std::string, Date&, Time&);
	void calcMonthlyTicketSales(std::vector <Ticket>&, int&);


#endif // TICKET_H_INCLUDED
