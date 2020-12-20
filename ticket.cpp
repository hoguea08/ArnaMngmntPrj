#include "date.h"
#include "time.h"
#include "bank.h"
#include "ticket.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

/// Reads and stores data from ticket.txt file and calculates existing ticket sales
void Ticket::readTicketData(fstream& infile, Bank& account)
{
    double cash, sales = 0;
    infile >> section >>  seat >> price >> sold >> event;
    if (sold == 1)
        sales += 45.00;
    cash = account.getCashOnHand() + sales;
    account.setCashOnHand(cash);
    sales = account.getTotalSales() + sales;
    account.setTotalSales(sales);
    return;
}

/// Ticket menu options
void ticketOptions(vector <Ticket>& ticket, Bank& account, int& tickSize) {
	int option = 0;
	while (option != 8)
	{
		cout << "\n1. Show all ticket info \n2. Show all available tickets \n"
		     << "3. Show all unavailable tickets \n4. Sell/Refund ticket \n"
		     << "5. Update ticket info \n6. Print ticket by event/date\n"
		     << "7. Calculate monthly ticket sales \n8. Return to Main Menu \n\nChoose an option: ";
		cin >> option;

		switch (option)
		{
			case 1: {
				displayAllTickets(ticket, tickSize);
				break;}
			case 2: {
				displayAvailTickets(ticket, tickSize);
				break;}
			case 3: {
				displayUnavailTickets(ticket, tickSize);
				break;}
			case 4: {
				sellRefundOption(ticket, tickSize, account);
				break;}
			case 5: {
				changeTicket(ticket, tickSize);
				break;}
			case 6: {
				searchForTicket(ticket, tickSize);
				break;}
            case 7: {
                calcMonthlyTicketSales(ticket, tickSize);
                break;}
		}
	}
}

/// Displays all tickets
void displayAllTickets(vector <Ticket>& ticket, int& tickSize)  {

for (int i = 0; i < tickSize; i++)
{
    cout << "Section: " << ticket[i].getSection() << "\nSeat: " << ticket[i].getSeat()
         << "\nPrice: " << fixed << setprecision(2) << ticket[i].getPrice()
         << "\nDate: " << ticket[i].getDateMonth() << "/" << ticket[i].getDateDay()
         << "/" << ticket[i].getDateYear() << "\nTime: " << ticket[i].getTimeHour()
         << ":";
         if (ticket[i].getTimeMinute() == 0)
            cout << "00";
         else
            cout << ticket[i].getTimeMinute();

         if (ticket[i].getSold() == true)
            cout << "\nAvailable? No  ";
         else
            cout << "\nAvailable? Yes  ";
    cout << "\nEvent: "<< ticket[i].getEvent() << "\n--------------------\n";
}
}

/// Displays available tickets
void displayAvailTickets(vector <Ticket>& ticket, int& tickSize)  {
        cout << "\nAvailable tickets: \n";
        cout << "--------------------\n";
    for (int i = 0; i < tickSize; i++)
    {
		if (ticket[i].getSold() == false)
		{
            cout << "Section: " << ticket[i].getSection() << "\nSeat: " << ticket[i].getSeat()
                 << "\nPrice: " << fixed << setprecision(2) << ticket[i].getPrice()
                 << "\nDate: " << ticket[i].getDateMonth() << "/" << ticket[i].getDateDay()
                 << "/" << ticket[i].getDateYear() << "\nTime: " << ticket[i].getTimeHour()
                 << ":";
                if (ticket[i].getTimeMinute() == 0)
                    cout << "00";
                else
                    cout << ticket[i].getTimeMinute();
            cout << "\nEvent: "<< ticket[i].getEvent() << "\n--------------------\n";
		}
    }
}

/// Displays unavailable tickets
void displayUnavailTickets(vector <Ticket>& ticket, int& tickSize)  {
        cout << "Unavailable tickets: \n";
    for (int i = 0; i < tickSize; i++)
    {
		if (ticket[i].getSold() == true)
		{
            cout << "Section: " << ticket[i].getSection() << "\nSeat: " << ticket[i].getSeat()
                 << "\nPrice: " << fixed << setprecision(2) << ticket[i].getPrice()
                 << "\nDate: " << ticket[i].getDateMonth() << "/" << ticket[i].getDateDay()
                 << "/" << ticket[i].getDateYear() << "\nTime: " << ticket[i].getTimeHour()
                 << ":";
                if (ticket[i].getTimeMinute() == 0)
                    cout << "00";
                else
                    cout << ticket[i].getTimeMinute();
            cout << "\nEvent: "<< ticket[i].getEvent() << "\n--------------------\n";
		}
    }
}

/// Menu option to refund or sell tickets
void sellRefundOption(vector <Ticket>& ticket, int& tickSize, Bank& account)  {

	int option = 0;
	while (option != 3)
	{
		cout << "1. Sell ticket \n2. Refund ticket \n3. Return to Ticket Menu\n\nChoose an option: ";
		cin >> option;
		switch (option)
		{
			case 1: {
				sellTicket(ticket, tickSize, account);
				break;}
			case 2: {
				refundTicket(ticket, tickSize, account);
				break;}
		}
	}
}

/// Function to sell tickets
void sellTicket(vector <Ticket>& ticket, int& tickSize, Bank& account)  {

	string eventOption;
	int section, seat;

	char option = 'y';
	while (option != 'n')  {
	cout << "Please enter an event: ";
	cin >> eventOption;
	cout << "\nPlease choose a section and a seat (separated by a space): ";
	cin >> section >> seat;
	for (int i = 0; i < tickSize; i++)
	{
		if (ticket[i].getSection() == section && ticket[i].getSeat() == seat && eventOption.compare(ticket[i].getEvent()) == 0)
		{
		    if (ticket[i].getSection() == section && ticket[i].getSeat() == seat && eventOption.compare(ticket[i].getEvent()) == 0 && ticket[i].getSold() == false)
			{
			    cout << "\nThank you, your ticket has been purchased.\n";
                ticket[i].setSold(1);
                char refund = 'n';
                account.calculateCashOnHandAndDebt(45.00, refund);
			}
			else if (ticket[i].getSold() == true)
            {
                cout << "I'm sorry, that ticket is not available for purchase.\n";
            }
		}
	}
	cout << "Would you like to purchase more tickets? <y/n>  ";
	cin >> option;
	cout << endl;
	}
}

/// Function to refund a sold ticket
void refundTicket(vector <Ticket>& ticket, int& tickSize, Bank& account)  {

	string eventOption;
	int section, seat;
	char option = 'y';
	while (option != 'n')  {
	cout << "Please enter the event your ticket is for: ";
	cin >> eventOption;
	cout << "\nPlease enter the section and seat numbers for the ticket to be refunded (separated by a space): ";
	cin >> section >> seat;

	for (int i = 0; i < tickSize; i++)
	{
		if (ticket[i].getSection() == section && ticket[i].getSeat() == seat && eventOption.compare(ticket[i].getEvent()) == 0)
		{
			cout << "\nThank you, the price for your ticket has been refunded.\n";
			ticket[i].setSold(0);
			char refund = 'y';
			account.calculateCashOnHandAndDebt(-45.00, refund);
		}
	}
	cout << "Do you need to submit a refund request for more tickets? <y/n>  ";
	cin >> option;
	cout << endl;
	}
}

/// Function to change a ticket event, section, and seat
void changeTicket(vector <Ticket>& ticket, int& tickSize)  {
	string eventOption, newEventOption;
	int section, seat, newSection, newSeat;
	char option = 'y';
	while (option != 'n')  {
	cout << "Please enter the event your ticket is for: ";
	cin >> eventOption;
	cout << "\nPlease enter the section and seat numbers for your ticket (separated by a space): ";
	cin >> section >> seat;

	for (int i = 0; i < tickSize; i++)
	{
		if (ticket[i].getSection() == section && ticket[i].getSeat() == seat && eventOption.compare(ticket[i].getEvent()) == 0)
		{
			ticket[i].setSold(0);
			cout << "\nThank you, please enter the new event (if the event is not changing, re-enter it): ";
			cin >> newEventOption;
			cout << "\nNow enter the new section and seat numbers (separated by a space): ";
			cin >> newSection >> newSeat;
			for (int j = 0; j < tickSize; ++j)
			{
				if (ticket[j].getSection() == newSection && ticket[j].getSeat() == newSeat && newEventOption.compare(ticket[j].getEvent()) == 0 && ticket[j].getSold() == false)
				{
					ticket[j].setSold(1);
					cout << "\nThank you. Your ticket has been changed.";
				}
			}
		}
	}
	cout << "\n\nDo you need to change more tickets? <y/n>  ";
	cin >> option;
	cout << endl;
	}
}

/// Searches for tickets by event name or date
void searchForTicket(vector <Ticket>& ticket,int& tickSize)  {
	int option = 0;
	string event1, event2;
	char c;
	Date eventDate;

	while (option != 3)
	{
	cout << "\n1. Search for ticket by event \n2. Search for ticket by date \n3. Return to previous menu \n\nChoose an option: ";
	cin >>  option;
	cout << endl;
	switch (option)
	{
		case 1:
		{
			cout << "\nEnter an event: ";
			cin >> event1;
			cout << "Tickets for this event: \n";
			for (int i = 0; i < tickSize; i++)
			{
				if (event1.compare(ticket[i].getEvent()) == 0)
				{
                    cout << "Section: " << ticket[i].getSection() << "\nSeat: " << ticket[i].getSeat()
                         << "\nPrice: " << fixed << setprecision(2) << ticket[i].getPrice()
                         << "\nDate: " << ticket[i].getDateMonth() << "/" << ticket[i].getDateDay()
                         << "/" << ticket[i].getDateYear() << "\nTime: " << ticket[i].getTimeHour()
                         << ":";
                        if (ticket[i].getTimeMinute() == 0)
                            cout << "00";
                        else
                            cout << ticket[i].getTimeMinute();
                        if (ticket[i].getSold() == true)
                            cout << "\nAvailable? No  ";
                        else
                            cout << "\nAvailable? Yes  ";
                    cout << "\n--------------------\n";
                }
            }
			break;
		}
		case 2:
		{
		    cout << "\nEnter a date (MM/DD/YYYY): ";
			cin >> eventDate.month >> c >> eventDate.day >> c >> eventDate.year;
			cout << "\nTickets for this date: \n";
			for (int i = 0; i < tickSize; i++)
			{
				if (eventDate.month == ticket[i].getDateMonth() && eventDate.day == ticket[i].getDateDay())
				{
                    cout << "Section: " << ticket[i].getSection() << "\nSeat: " << ticket[i].getSeat()
                         << "\nPrice: " << fixed << setprecision(2) << ticket[i].getPrice()
                         << "\nTime: " << ticket[i].getTimeHour() << ":";
                        if (ticket[i].getTimeMinute() == 0)
                            cout << "00";
                        else
                            cout << ticket[i].getTimeMinute();
                        if (ticket[i].getSold() == true)
                            cout << "\nAvailable? No  ";
                        else
                            cout << "\nAvailable? Yes  ";
                    cout << "\nEvent: "<< ticket[i].getEvent() << "\n--------------------\n";
                }
            }
			break;
		}
	}
	cout << endl;
	}
}

/// Function to create new tickets
void createTickets(vector <Ticket>& ticket, int& tickSize, string eventName, Date& d, Time& t)
{
	int temp = tickSize;
	tickSize += 500;
	ticket.resize(tickSize);

	for (int i = temp; i < tickSize; i++)
	{
		for (int section = 0; section < 50; section++)
		{
			for (int seat = 0; seat < 10; seat++)
			{
				ticket[i].setSection(section);
				ticket[i].setSeat(seat);
                ticket[i].setEvent(eventName);
				ticket[i].setPrice(45.00);
				ticket[i].setSold(0);
				ticket[i].setDateMonth(d.month);
				ticket[i].setDateDay(d.day);
				ticket[i].setDateYear(d.year);
				ticket[i].setTimeHour(t.hour);
				ticket[i].setTimeMinute(t.minute);
				i++;
			}
		}
	}
}

/// Function to calculate monthly ticket sales according to event date
void calcMonthlyTicketSales(std::vector <Ticket>& ticket, int& tickSize)
{
    int month;
    double sales = 0.0;
    cout << "For which month would you like to calculate ticket sales? (Enter the \n"
         << "numerical month, ex. January = 1) ";
    cin >> month;

    for (int i = 0; i < tickSize; i++)
    {
        if (ticket[i].getDateMonth() == month)
        {
            sales += 45.00;
        }
    }

    string m;
    switch (month)
    {
        case 1:
        {
            m = "January";
            break;
        }
        case 2:
        {
            m = "February";
            break;
        }
        case 3:
        {
            m = "March";
            break;
        }
        case 4:
        {
            m = "April";
            break;
        }
        case 5:
        {
            m = "May";
            break;
        }
        case 6:
        {
            m = "June";
            break;
        }
        case 7:
        {
            m = "July";
            break;
        }
        case 8:
        {
            m = "August";
            break;
        }
        case 9:
        {
            m = "September";
            break;
        }
        case 10:
        {
            m = "October";
            break;
        }
        case 11:
        {
            m = "November";
            break;
        }
        case 12:
        {
            m = "December";
            break;
        }
    }
    cout << "\nThe total sales amount for the month of " << m << " is: $"
         << fixed << setprecision(2) << sales << endl;
}


