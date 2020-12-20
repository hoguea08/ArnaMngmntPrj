#include "date.h"
#include "time.h"
#include "ticket.h"
#include "schedule.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

/// Overloading "==" operator
bool operator== (const Schedule &s1, const Schedule &s2)
{
        return s1.date.day == s2.date.day;
}

/// Reads schedule data from text file
void Schedule::readSchedData(fstream& infile)
{
    char c;
	infile >> event >> date.month >> c >> date.day >> c >> date.year >> time.hour >> c >> time.minute;
	return;
}

/// Schedule menu options
void scheduleOptions(vector <Schedule>& schedule, int& schedSize, vector <Ticket>& ticket, int& tickSize, Bank& account)  {
    int option = 0;
    while (option != 5)
    {
    cout << "\n1. Print events \n2. Create new event \n3. Change an event \n4. Cancel an event \n5. Return to Main Menu";
    cout << "\nChoose an option: ";
    cin >> option;
    cout << endl;

    switch (option)
    {
        case 1:
        {
            printEventInfo(schedule, schedSize);
            break;
        }
        case 2:
        {
            createNewEvent(schedule, schedSize, ticket, tickSize);
            break;
        }
        case 3:
        {
            changeEvent(schedule, schedSize, ticket, tickSize);
            break;
        }
        case 4:
        {
            cancelEvent(schedule, schedSize, account, ticket, tickSize);
            break;
        }
    }
    }
}

/// Prints events with options to print all events or print events by date
void printEventInfo(vector <Schedule>& schedule, int& schedSize)  {
    int option = 0;
    int month, day, year;
    char c;
    while (option != 3)
    {
    cout << "1. Print all events \n2. Print event by date \n3. Return to previous menu \nChoose an option: ";
    cin >> option;
    cout << endl;
    switch (option)
    {
        case 1:
        {
            for (int i = 0; i < schedSize; i++)
            {
                cout << "Event: " << schedule[i].getEvent() << "\nDate: " << schedule[i].getDateMonth() << "/"
                    << schedule[i].getDateDay() << "/" << schedule[i].getDateYear() << "\nTime: "
                    << schedule[i].getTimeHour() << ":";
                    if (schedule[i].getTimeMinute() == 0)
                    {
                        cout << "00"<< endl;
                    }
                    else
                    {
                        cout << schedule[i].getTimeMinute() << endl;
                    }
                cout << "\n---------------------\n";
            }
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "Enter a date (MM/DD/YYYY): ";
            cin >> month >> c >> day >> c >> year;
            cout << endl << endl
                 << "Events for this day:\n"
                 << "--------------------\n";               ;

            for (int i = 0; i < schedSize; i++)
            {
                if (month == schedule[i].getDateMonth() && day == schedule[i].getDateDay() && year == schedule[i].getDateYear())
                {
                    cout << "Event: " << schedule[i].getEvent() << "\nDate: " << schedule[i].getDateMonth() << "/"
                        << schedule[i].getDateDay() << "/" << schedule[i].getDateYear() << "\nTime: "
                        << schedule[i].getTimeHour() << ":";
                        if (schedule[i].getTimeMinute() == 0)
                        {
                            cout << "00"<< endl;
                        }
                        else
                        {
                            cout << schedule[i].getTimeMinute() << endl;
                        }
                    cout << "\n---------------------\n";
                }
            }
            cout << endl;
            break;
        }
    }
    }
}

/// Creates a new event and generates new tickets
void createNewEvent(vector <Schedule>& schedule, int& schedSize, vector <Ticket>& ticket, int& tickSize)  {
    string eventName;
    Date date;
    Time time;
    char c;
    char option = 'y';
    while (option != 'n')
    {
        cout << "\n\nPlease enter name of new event: ";
        cin >> eventName;
        cout << "\nPlease enter the date of the event (MM/DD/YYYY): ";
        cin >> date.month >> c >> date.day >> c >> date.year;
        cout << "\nPlease enter the time of the event (24 hour format) (HH:MM): ";
        cin >> time.hour >> c >> time.minute;
        schedSize++;
        schedule.resize(schedSize);
        schedule[schedSize-1].setEvent(eventName);
        schedule[schedSize-1].setDateMonth(date.month);
        schedule[schedSize-1].setDateDay(date.day);
        schedule[schedSize-1].setDateYear(date.year);
        schedule[schedSize-1].setTimeHour(time.hour);
        schedule[schedSize-1].setTimeMinute(time.minute);
        createTickets(ticket, tickSize, eventName, date, time);
        cout << "\nThank you, your event has been created and tickets are available.\n\n";
        cout << "Would you like to create another event? <y/n> ";
        cin >> option;
    }
}

/// Function to change event name, date, and time
void changeEvent(vector <Schedule>& schedule, int& schedSize, vector <Ticket>& ticket, int& tickSize)  {

    char option = 'y';
	int option2 = 0;
	string eventName;

		while (option != 'n')
		{
        cout << "\n\n1. Change event name \n2. Change event date \n3. Change event time \n4. Previous menu \nChoose an option: ";
		cin >> option2;
		cout << "Enter the event you'd like to change: ";
		cin >> eventName;
		for (int i = 0; i < schedSize; i++)
		{
			if (eventName.compare(schedule[i].getEvent()) == 0)
			{
				cout << "\n\nEvent information: " << schedule[i].getEvent() << "\nDate: " << schedule[i].getDateMonth() << "/"
				     << schedule[i].getDateDay() << "/" << schedule[i].getDateYear() << "\nTime: " << schedule[i].getTimeHour()
				     << ":";
				     if (schedule[i].getTimeMinute() == 0)
                    {
                        cout << "00"<< endl;
                    }
                    else
                    {
                        cout << schedule[i].getTimeMinute() << endl;
                    }
			}
		}
		switch (option2)
		{
			case 1:
			{
				string newEvent;
				cout << "\n\nPlease enter the updated event name: ";
				cin >> newEvent;
				for (int i = 0; i < schedSize; i++)
				{
					if (eventName.compare(schedule[i].getEvent()) == 0)
					{
						schedule[i].setEvent(newEvent);
					}
				}
				for (int j = 0; j < tickSize; j++)
				{
					if (eventName.compare(ticket[j].getEvent()) == 0)
					{
						ticket[j].setEvent(newEvent);
					}
				}
				cout << "\nThank you, the event name has been changed and tickets have been updated.\n\n";
				break;
			}
			case 2:
			{
				int month, day, year;
				char c;
				cout << "\n\nPlease enter a new date (MM/DD/YYYY): ";
				cin >> month >> c >> day >> c >> year;
				for (int i = 0; i < schedSize; i++)
				{
					if (eventName.compare(schedule[i].getEvent()) == 0)
					{
						schedule[i].setDateMonth(month);
						schedule[i].setDateDay(day);
						schedule[i].setDateYear(year);
					}
				}
				for (int i = 0; i < tickSize; i++)
                {
                    if (eventName.compare(ticket[i].getEvent()) == 0)
                    {
                        ticket[i].setDateMonth(month);
                        ticket[i].setDateDay(day);
                        ticket[i].setDateYear(year);
                    }
                }
				cout << "\nThank you, the event listing and tickets have been updated.\n\n";
				break;
			}
			case 3:
			{
				int hour, minute;
				char c;
				cout << "Please enter the updated event time in 24 hour format (HH:MM): ";
				cin >> hour >> c >> minute;
				for (int i = 0; i < schedSize; i++)
				{
					if (eventName.compare(schedule[i].getEvent()) == 0)
					{
						schedule[i].setTimeHour(hour);
						schedule[i].setTimeMinute(minute);
					}
				}
				for (int i = 0; i < tickSize; i++)
                {
                    if (eventName.compare(ticket[i].getEvent()) == 0)
                    {
                        ticket[i].setTimeHour(hour);
                        ticket[i].setTimeMinute(minute);
                    }
                }
				cout << "\nThank you, the event listing and tickets have been updated.\n\n";
				break;
			}
			case 4:
                break;
		}
		cout << "Would you like to make another change? <y/n> ";
		cin >> option;
	}
}

/// Cancels an event and refunds tickets
void cancelEvent(vector <Schedule>& schedule, int& schedSize, Bank& account, vector <Ticket>& ticket, int& tickSize)  {

	string eventName;
	char option1 = 'y';
	char option2;
	int refund = 0;
	while (option1 != 'n')
	{
	cout << "\nPlease enter the name of the event you wish to cancel: ";
	cin >> eventName;
	cout << endl;
	for (int i = 0; i < schedSize; i++)
	{
		if (eventName.compare(schedule[i].getEvent()) == 0)
		{
			cout << schedule[i].getEvent() << " " << schedule[i].getDateMonth() << "/"
			     << schedule[i].getDateDay() << "/" << schedule[i].getDateYear() << " "
			     << schedule[i].getTimeHour() << ":";
			     if (schedule[i].getTimeMinute() == 0)
                    {
                        cout << "00"<< endl;
                    }
                    else
                    {
                        cout << schedule[i].getTimeMinute() << endl;
                    }
            cout << "\nIs this the event you wish to cancel? <y/n> ";
			cin >> option2;
				if (option2 == 'y')
				{
					cout << "\nThank you. The event has been canceled and all tickets refunded.\n\n";
					for (int j = 0; j < tickSize; j++)
					{
						if (eventName.compare(ticket[j].getEvent()) == 0)
						{
							ticket.erase(ticket.begin()+j);
							refund++;
						}
					}
					char r = 'y';
					account.calculateCashOnHandAndDebt(refund * (-45.00), r);
                    schedule.erase(schedule.begin()+i);
				    schedSize--;
				    tickSize -= refund;
				    ticket.resize(tickSize);
				}
				else
					break;
		}
	}
	cout << "Would you like to cancel another event? <y/n> ";
	cin >> option1;
	cout << endl;
	}
}
