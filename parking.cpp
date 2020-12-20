#include "bank.h"
#include "parking.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/// Reads parking data from text file
void Parking::readParkingData(std::fstream& infile)
{
    infile >> section >> space >> price >> available;
    return;
}

/// Parking menu options
void parkingOptions(Parking parking[], int& parkSize, Bank& account)
{
    int option = 0;
    while (option != 7)
    {
        cout << "\n1. Print all parking information \n2. Print parking by section"
             << "\n3. Sell parking spaces \n4. Refund parking spaces \n5. Change availability of parking spaces \n7. Return to Main Menu "
             << "\n\nChoose an option: ";
        cin >> option;
        cout << endl;
        switch (option)
        {
        case 1:
            {
                printParking(parking, parkSize);
                break;
            }
        case 2:
            {
                printBySection(parking, parkSize);
                break;
            }
        case 3:
            {
                sellParkingSpot(parking, parkSize, account);
                break;
            }
        case 4:
            {
                refundParkingSpot(parking, parkSize, account);
                break;
            }
        case 5:
            {
                changeParkingSpot(parking, parkSize);
                break;
            }
        }
    }
}

/// Prints parking info
void printParking(Parking parking[], int& parkSize)
{
    for (int i = 0; i < parkSize; i++)
    {
        cout << "Section: " << parking[i].getSection() << "\nSpace: " << parking[i].getSpace()
             << "\nPrice: " << fixed << setprecision(2) << parking[i].getPrice();
        if (parking[i].getAvailable() == true)
                cout << "\nAvailable? Yes  ";
            else
                cout << "\nAvailable? No  ";
        cout << "\n--------------------\n";
    }
}

/// Prints parking by section
void printBySection(Parking parking[], int& parkSize)
{
    int section;
    cout << "Enter a section to print parking spaces: ";
    cin >> section;
    cout << endl;

    for (int i = 0; i < parkSize; i++)
    {
        if (section == parking[i].getSection())
        {
            cout << "Section: " << parking[i].getSection() << "\nSpace: " << parking[i].getSpace()
                 << "\nPrice: " << fixed << setprecision(2) << parking[i].getPrice();
                if (parking[i].getAvailable() == true)
                    cout << "\nAvailable? Yes  ";
                else
                    cout << "\nAvailable? No  ";
            cout << "\n--------------------\n";
        }
    }
}

/// Changes availability of parking space
void Parking::changeAvailability()
{
    if (available == true)
        available = false;
    else if (available == false)
        available = true;
}

/// Sells a parking space
void sellParkingSpot(Parking parking[], int& parkSize, Bank& account)
{
    int section, space;
    cout << "Enter the section and space of the parking spot to be sold: ";
    cin >> section >> space;
    for (int i = 0; i < parkSize; i++)
    {
        if (section == parking[i].getSection() && space == parking[i].getSpace() && parking[i].getAvailable() == 1)
        {
            parking[i].changeAvailability();
            char refund = 'n';
            account.calculateCashOnHandAndDebt(10.00, refund);
            cout << "\nThank you, the purchase has been made and account updated.\n";
        }
        else if (section == parking[i].getSection() && space == parking[i].getSpace() && parking[i].getAvailable() == 0)
            cout << "\nThat space has already been sold.\n";
    }
}

/// Refunds money for a parking space
void refundParkingSpot(Parking parking[], int& parkSize, Bank& account)
{
    int section, space;
    cout << "Enter the section and space of the parking spot to be refunded: ";
    cin >> section >> space;
    for (int i = 0; i < parkSize; i++)
    {
        if (section == parking[i].getSection() && space == parking[i].getSpace() && parking[i].getAvailable() == 0)
        {
            parking[i].changeAvailability();
            char refund = 'y';
            account.calculateCashOnHandAndDebt(-10.00, refund);
            cout << "\nThank you, the refund has been made and account updated.\n";
        }
        else if (section == parking[i].getSection() && space == parking[i].getSpace() && parking[i].getAvailable() == 1)
            cout << "\nThat space has not been sold yet and cannot be refunded.\n";
    }
}

/// Change the availability of a specific parking space
void changeParkingSpot(Parking parking[], int& parkSize)
{
    char option = 'y';
    while (option!= 'n')
    {
        int section, space;
        cout << "Enter the section and space of the parking spot to change the "
             << "availability (separate the numbers by a space): ";
        cin >> section >> space;

        for (int i = 0; i < parkSize; i++)
        {
            if (section == parking[i].getSection() && space == parking[i].getSpace())
            {
                parking[i].changeAvailability();
            }
        }
        cout << "\nThank you, the change has been made.\n";
        cout << "\nWould you like to change the availability of another parking space <y/n>? ";
        cin >> option;
    }
}
