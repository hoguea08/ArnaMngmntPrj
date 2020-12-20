#include "bank.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

/// Reads bank account data from text file
void Bank::readBankData(std::fstream& infile)
{
    infile >> totalSales >> cashOnHand >> debt;
    return;
}

/// Bank menu options
void bankOptions(Bank& account)
{
    int option = 0;
    while (option != 4)
    {
        cout << "\n1. Print account information \n2. Adjust cash on hand \n3. Pay off debt"
             << "\n4. Return to Main Menu \n\nChoose an option: ";
        cin >> option;
        cout << endl;

        switch (option)
        {
            case 1:
            {
                printAcctInfo(account);
                break;
            }
            case 2:
            {
                double cash;
                cout << "\nHow much cash would you like to add? ";
                cin >> cash;
                addCashOnHand(account, cash);
                cout << "\n\nThank you, that amount has been added to Cash On Hand." << endl;
                break;
            }
            case 3:
            {
                double amount;
                cout << "There is $" << fixed << setprecision(2) << account.getDebt() << " in debt."
                     << "\nHow much would you like to pay off? ";
                cin >> amount;
                payOffDebt(account, amount);
                cout << "\n\nThank you, that amount has been paid towards the debt." << endl;
                break;
            }
        }
    }
}

/// Adds amount chosen by user to cash on hand
void addCashOnHand(Bank& account, double cash)
{
    double coh = account.getCashOnHand() + cash;
    account.setCashOnHand(coh);
}

/// Uses cash on hand to pay an amount chosen by user towards debt
void payOffDebt(Bank& account, double amount)
{
    double debt = account.getDebt() - amount;
    account.setDebt(debt);
    double cash = account.getCashOnHand() - amount;
    account.setCashOnHand(cash);
}

/// Calculates total sales, cash on hand, and debt for different transactions
void Bank::calculateCashOnHandAndDebt(double netSales, char& option)  {
	if (netSales >= 0)
    {
        totalSales += netSales;
        cashOnHand += netSales;
    }
    else if (netSales < 0)
    {
        if (option == 'y')
        {
            totalSales += netSales;
            cashOnHand += netSales;
        }
        else
        {
            cashOnHand += netSales;
        }

        if (cashOnHand < 0)
        {
            double temp = std::abs(cashOnHand);
            debt += temp;
            cashOnHand += temp;
        }
    }
}

/// Print bank account info
void printAcctInfo(Bank& account)
{
    cout << "\nTotal Sales   Cash On Hand   Debt"
         << "\n---------------------------------\n"
         << setw(8) << fixed << setprecision(2) << account.getTotalSales()
         << setw(12) << fixed << setprecision(2) << account.getCashOnHand()
         << setw(13) << fixed << setprecision(2) << account.getDebt() << endl;
}
