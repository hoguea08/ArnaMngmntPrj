#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "staff.h"

using namespace std;

/// Reads staff data from text file
void Staff::readStaffData(fstream& infile)
{
    infile >> empID >> firstName >> lastName >> jobTitle >> salary;
}

/// Prints staff information
void printStaff(vector <Staff>& staff, int& staffSize)
{
	cout << "ID #        Name        Job Title   Salary\n";
	cout << "------------------------------------------\n";
	for (int i = 0; i < staffSize; i++)
	{
		cout << left << setw(4) << staff[i].getEmpID() << "  ";
		cout << right << setw(7) << staff[i].getFirstName();
		cout << left << " " << setw(7) << staff[i].getLastName();
        cout << right << setfill(' ') << setw(12) << staff[i].getJobTitle() << "  ";
		cout << right << fixed << setprecision(2) << staff[i].getSalary() << endl;
	}
}

/// Staff menu options
void staffOptions(vector <Staff>& staff, int& staffSize)
{
	int option = 0;
	while (option != 7)
	{
		cout << "1. Print staff \n2. Print staff by ID number \n3. Print staff by job title \n4. Hire staff \n";
		cout << "5. Fire staff \n6. Change staff information \n7. Return to previous menu \n\nChoose an option: ";
		cin >> option;
		cout << endl;
		switch (option)
		{
			case 1:
			{
				printStaff(staff, staffSize);
				cout << endl;
				break;
			}
			case 2:
			{
				printByID(staff, staffSize);
				cout << endl;
				break;
			}
			case 3:
			{
				printByPosition(staff, staffSize);
				cout << endl;
				break;
			}
			case 4:
			{
				hireStaff(staff, staffSize);
				cout << endl;
				break;
			}
			case 5:
			{
				fireStaff(staff, staffSize);
				cout << endl;
				break;
			}
			case 6:
            {
                changeStaff(staff, staffSize);
                cout << endl;
                break;
            }
        }
	}
}

/// Prints staff by employee ID
void printByID(vector <Staff>& staff, int& staffSize)
{
	int empID;
	cout << "Enter an employee ID number to print employee information: ";
	cin >> empID;
	cout << endl;
    cout << "ID #        Name        Job Title   Salary\n";
    cout << "------------------------------------------\n";
	for (int i = 0; i < staffSize; i++)
	{
		if (empID == staff[i].getEmpID())
		{
                cout << left << setw(4) << staff[i].getEmpID() << "  ";
                cout << right << setw(7) << staff[i].getFirstName();
                cout << left << " " << setw(7) << staff[i].getLastName();
                cout << right << setfill(' ') << setw(12) << staff[i].getJobTitle() << "  ";
                cout << right << fixed << setprecision(2) << staff[i].getSalary() << endl;
		}
	}
}

/// Prints staff by job title
void printByPosition(vector <Staff>& staff, int& staffSize)
{
	string position;
	cout << "Enter a job title to print employees filling that position: ";
	cin >> position;
	cout << endl;
	cout << "ID #        Name        Job Title   Salary\n";
	cout << "------------------------------------------\n";
	for (int i = 0; i < staffSize; i++)
	{
		if (position.compare(staff[i].getJobTitle()) == 0)
		{
                cout << left << setw(4) << staff[i].getEmpID() << "  ";
                cout << right << setw(7) << staff[i].getFirstName();
                cout << left << " " << setw(7) << staff[i].getLastName();
                cout << right << setfill(' ') << setw(12) << staff[i].getJobTitle() << "  ";
                cout << right << fixed << setprecision(2) << staff[i].getSalary() << endl;
		}
	}
}

/// Hires new staff members
void hireStaff(vector <Staff>& staff, int& staffSize)
{
	string first, last, job;
	double sal;
	int empID;

	cout << "\nPlease enter the first and last names of the new employee: ";
	cin >> first >> last;

	cout  << "\nEnter a four digit employee ID number: ";
	cin >> empID;

	cout << "\nNow enter the job title for this employee: ";
	cin >> job;

	cout << "\nLast, enter the salary for this employee: ";
	cin >> sal;

	staffSize++;
	staff.resize(staffSize);
	staff[staffSize-1].setEmpID(empID);

	cout << "Thank you, the new employee has been added." << endl;
	staff[staffSize-1].setFirstName(first);
	staff[staffSize-1].setLastName(last);
	staff[staffSize-1].setJobTitle(job);
	staff[staffSize-1].setSalary(sal);
}

/// Fires existing staff members
void fireStaff(vector <Staff>& staff, int& staffSize)
{
	string first, last;
	cout << "Enter the name of the employee to be fired: ";
	cin >> first >> last;

	for (int i = 0; i < staffSize; i++)
	{
		if (first.compare(staff[i].getFirstName()) == 0 && last.compare(staff[i].getLastName()) == 0)
		{
		    staff.erase(staff.begin()+i);
		}
	}
	staffSize--;
	staff.resize(staffSize);
	cout << "\nThis employee has been taken off the payroll.\n";
}

/// Changes staff information
void changeStaff(vector <Staff>& staff, int& staffSize)
{
    string first, last, newFirst, newLast, newJob;
    double newSal;
    int newID;
	cout << "Enter the name of the employee whose information needs to be adjusted: ";
	cin >> first >> last;

	int option;
	cout << "\n1. Name \n2. Employee ID \n3. Position"
         << "\n4. Salary\n\nWhat would you like to change? ";
    cin >> option;

    switch (option)
    {
        case 1:
        {
           for (int i = 0; i < staffSize; i++)
            {
                if (first.compare(staff[i].getFirstName()) == 0 && last.compare(staff[i].getLastName()) == 0)
                {
                    cout << "Enter the new name: ";
                    cin >> newFirst >> newLast;
                    staff[i].setFirstName(newFirst);
                    staff[i].setLastName(newLast);
                    cout << "\n\nThank you, the employee's name has been updated.\n";
                }
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < staffSize; i++)
            {
                if (first.compare(staff[i].getFirstName()) == 0 && last.compare(staff[i].getLastName()) == 0)
                {
                    cout << "Enter the new four digit Employee ID: ";
                    cin >> newID;
                    staff[i].setEmpID(newID);
                    cout << "\n\nThank you, the employee's ID has been updated.\n";
                }
            }
            break;
        }
        case 3:
        {
            for (int i = 0; i < staffSize; i++)
            {
                if (first.compare(staff[i].getFirstName()) == 0 && last.compare(staff[i].getLastName()) == 0)
                {
                    cout << "Enter the new job title: ";
                    cin >> newJob;
                    staff[i].setJobTitle(newJob);
                    cout << "\n\nThank you, the employee's job title has been updated.\n";
                }
            }
            break;
        }
        case 4:
        {
            for (int i = 0; i < staffSize; i++)
            {
                if (first.compare(staff[i].getFirstName()) == 0 && last.compare(staff[i].getLastName()) == 0)
                {
                    cout << "Enter the new salary: ";
                    cin >> newSal;
                    staff[i].setSalary(newSal);
                    cout << "\n\nThank you, the employee's salary has been updated.\n";
                }
            }
            break;
        }
    }
}
