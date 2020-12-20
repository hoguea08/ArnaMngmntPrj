#include "ticket.h"
#include "schedule.h"
#include "parking.h"
#include "concession.h"
#include "staff.h"
#include "bank.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/// Calculates initial size of vectors
int calculateSize(fstream&);

/// Beginning of main.cpp
int main()
{
    int option = 0;

    fstream ticketInfile;
	fstream bankInfile;
	fstream schedInfile;
	fstream concInfile;
	fstream staffInfile;
	fstream parkInfile;

	ticketInfile.open("ticket.txt");
	schedInfile.open("schedule.txt");
	bankInfile.open("bank.txt");
	concInfile.open("concession.txt");
	staffInfile.open("staff.txt");
	parkInfile.open("parking.txt");

	int tickSize, schedSize, staffSize, parkSize;

	tickSize = calculateSize(ticketInfile);
    schedSize = calculateSize(schedInfile);
    staffSize = calculateSize(staffInfile);
    parkSize = calculateSize(parkInfile);

    vector <Schedule> schedule(schedSize);
    vector <Ticket> ticket(tickSize);
    vector <Staff> staff(staffSize);
    Parking * parking = new Parking[parkSize];
    Concession concession;
	Bank account;

/// Read and store data from bank.txt file
	account.readBankData(bankInfile);

/// Read and store data from ticket.txt file
	for (int i = 0; i < tickSize; i++)
    {
        ticket[i].readTicketData(ticketInfile, account);
    }

/// Read and store data from schedule.txt file
    for (int i = 0; i < schedSize; i++)
    {
        schedule[i].readSchedData(schedInfile);
    }
/// Copy schedule event date into Ticket object for tickets of the same event
    for(int i = 0; i < schedSize; i++)
    {
        for (int j = 0; j < tickSize; j++)
        {
            if (schedule[i].getEvent().compare(ticket[j].getEvent()) == 0)
            {
                ticket[j].setDateMonth(schedule[i].getDateMonth());
                ticket[j].setDateDay(schedule[i].getDateDay());
                ticket[j].setDateYear(schedule[i].getDateYear());
                ticket[j].setTimeHour(schedule[i].getTimeHour());
                ticket[j].setTimeMinute(schedule[i].getTimeMinute());
            }
        }
    }

/// Read and store data from staff.txt file
    for (int i = 0; i < staffSize; i++)
    {
        staff[i].readStaffData(staffInfile);
    }

/// Read and store data from parking.txt file
    for (int i = 0; i < parkSize; i++)
    {
        parking[i].readParkingData(parkInfile);
    }

/// Read and store data from concession.txt file
    concession.readConcData(concInfile);

/// Begins Main Menu
	while (option != 7)
	{
		cout << "Main Menu:\n" << "1. Manage Tickets\n" << "2. Manage Schedule\n"
	     		<< "3. Manage Parking\n" << "4. Manage Staff\n" << "5. Manage Bank Account\n"
	     		<< "6. Manage Concession Stand\n" << "7. Exit\n\n" << "Choose an option: ";

		cin >> option;

		switch (option)
		{
			case 1:
            {
                ticketOptions(ticket, account, tickSize);
                break;
            }
			case 2:
            {
                scheduleOptions(schedule, schedSize, ticket, tickSize, account);
                break;
			}
			// Display Schedule/Event options
			case 3:
            {
                parkingOptions(parking, parkSize, account);
                break;
			}
			// Display Parking options
			case 4:
            {
                staffOptions(staff, staffSize);
                break;
            }
			// Display Staff options
			case 5:  {
                bankOptions(account);
                break;
			}

			// Display Bank Account options
			case 6:
            {
                concessionOptions(concession, account);
                break;
            }
			// Display Concession Stand options
		}

	}

    delete parking;
    ticketInfile.close();
    schedInfile.close();
    bankInfile.close();
    concInfile.close();
    staffInfile.close();
    parkInfile.close();

    return 0;
}

/// Function to calculate initial size of vectors
int calculateSize(fstream& infile)
{
    int numLines = 0;
    string line;

    while (getline(infile, line))
        numLines++;

    infile.clear();
    infile.seekg (0, ios::beg);

    return numLines;
}


