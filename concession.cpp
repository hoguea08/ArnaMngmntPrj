#include "bank.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "concession.h"

using namespace std;

/// Reads concession data from text file
void Concession::readConcData(std::fstream& infile)
{
    infile >> numHotDog >> priceHotDog >> numPeanuts >> pricePeanuts >> numBurgers
           >> priceBurgers >> numDrinks >> priceDrinks >> numBeer >> priceBeer
           >> numJersey >> priceJersey >> sales;
    return;
}

/// Concession menu options
void concessionOptions(Concession& concession, Bank& account)
{
	int option = 0;
	while (option != 5)
	{
		cout << "\n1. Print Total Concessions Sales \n2. Order New Inventory \n3. Sell Concessions Items"
		     << "\n4. Print Concessions Info/Inventory \n5. Return to Main Menu \n\nChoose an option: ";
		cin >> option;
		cout << endl;

        switch (option)
		{
			case 1:
			{
				totalConcessionSales(concession);
				break;
			}
			case 2:
			{
				orderNewInventory(concession, account);
				break;
			}
			case 3:
			{
				sellInventory(concession, account);
				break;
			}
			case 4:
			{
				printConcessionInfo(concession);
				break;
			}
		}
	}
}

/// Prints concession info
void printConcessionInfo(Concession& concession)
{
	cout << "\nItem    Quantity    Price\n";
	cout << "----------------------------";
	cout << left << setw(12) << "\nHot Dogs";
	cout << right << setw(7) << concession.getNumHotDog();
	cout << setw(8) << fixed << setprecision(2) << concession.getPriceHotDog();
	cout << left << setw(12) << "\nPeanuts";
	cout << right << setw(7) << concession.getNumPeanuts();
	cout << setw(8) << fixed << setprecision(2) << concession.getPricePeanuts();
	cout << left << setw(12) << "\nBurgers";
	cout << right << setw(7) << concession.getNumBurgers();
	cout << setw(8) << fixed << setprecision(2) << concession.getPriceBurgers();
	cout << left << setw(12) << "\nSoft Drinks";
	cout << right << setw(7) << concession.getNumDrinks();
	cout << setw(8) << fixed << setprecision(2) << concession.getPriceDrinks();
	cout << left << setw(12) << "\nBeer";
	cout << right << setw(7) << concession.getNumBeer();
	cout << setw(8) << fixed << setprecision(2) << concession.getPriceBeer();
	cout << left << setw(12) << "\nJerseys";
	cout << right << setw(7) << concession.getNumJersey();
	cout << setw(8) << fixed << setprecision(2) << concession.getPriceJersey();
    cout << endl << endl;
}

/// Displays total lifetime concession sales
void totalConcessionSales(Concession& concession)
{
	cout << "Total Concession Sales\n";
	cout << "----------------------\n";
	cout << "     " << fixed << setprecision(2) << concession.getSales() << endl;
}

/// Sell concession items from inventory
void sellInventory(Concession& concession, Bank& account)
{
	char option = 'y';
	int item = 0;
	while (option != 'n')
	{
		int numToSell = 0;
		cout << "\n1. Hot Dogs \n2. Peanuts \n3. Burgers \n4. Soft Drinks \n5. Beer \n6. Jerseys"
		     << "\n\nChoose an item to be sold: ";
		cin >> item;
		switch (item)
		{
			case 1:
			{
				if (concession.getNumHotDog() > 0)
				{
				cout << "\nHow many hot dogs would you like to sell? (Current inventory: " << concession.getNumHotDog() << " )\n";
				cin >> numToSell;

                int setHD = concession.getNumHotDog() - numToSell;
				concession.setNumHotDog(setHD);

				int setSales = concession.getSales() + (numToSell*concession.getPriceHotDog());
				concession.setSales(setSales);

				char refund = 'n';
				account.calculateCashOnHandAndDebt(numToSell * concession.getPriceHotDog(), refund);
				break;
				}
				else
				{
					cout << "I'm sorry, this item is sold out.\n";
					break;
				}
			}
			case 2:
			{
				if (concession.getNumPeanuts() > 0)
				{
				cout << "\nHow many peanuts would you like to sell? (Current inventory: " << concession.getNumPeanuts() << " )\n";
				cin >> numToSell;

				int setPeanuts = concession.getNumPeanuts() - numToSell;
				concession.setNumPeanuts(setPeanuts);

				int setSales = concession.getSales() + (numToSell * concession.getPricePeanuts());
				concession.setSales(setSales);

				char refund = 'n';
				account.calculateCashOnHandAndDebt(numToSell * concession.getPricePeanuts(), refund);
				break;
				}
				else
				{
					cout << "I'm sorry, this item is sold out.\n";
					break;
				}
			}
			case 3:
			{
				if (concession.getNumBurgers() > 0)
				{
				cout << "\nHow many burgers would you like to sell? (Current inventory: " << concession.getNumBurgers() << " )\n";
				cin >> numToSell;

                int setBurgers = concession.getNumBurgers() - numToSell;
				concession.setNumBurgers(setBurgers);

				int setSales = concession.getSales() + (concession.getPriceBurgers() * numToSell);
				concession.setSales(setSales);

				char refund = 'n';
				account.calculateCashOnHandAndDebt(numToSell * concession.getPriceBurgers(), refund);
				break;
				}
				else
				{
					cout << "I'm sorry, this item is sold out.\n";
					break;
				}
			}
			case 4:
			{
				if (concession.getNumDrinks() > 0)
				{
				cout << "\nHow many soft drinks would you like to sell? (Current inventory: " << concession.getNumDrinks() << " )\n";
				cin >> numToSell;

				int setDrinks = concession.getNumDrinks() - numToSell;
				concession.setNumDrinks(setDrinks);

				int setSales = concession.getSales() + (numToSell * concession.getPriceDrinks());
				concession.setSales(setSales);

				char refund = 'n';
				account.calculateCashOnHandAndDebt(numToSell * concession.getPriceDrinks(), refund);
				break;
				}
				else
				{
					cout << "I'm sorry, this item is sold out.\n";
					break;
				}
			}
			case 5:
			{
				if (concession.getNumBeer() > 0)
				{
				cout << "\nHow many beers would you like to sell? (Current inventory: " << concession.getNumBeer() << " )\n";
				cin >> numToSell;

				int setBeer = concession.getNumBeer() - numToSell;
				concession.setNumBeer(setBeer);

				int setSales = concession.getSales() + (numToSell * concession.getPriceBeer());
				concession.setSales(setSales);

				char refund = 'n';
				account.calculateCashOnHandAndDebt(numToSell * concession.getPriceBeer(), refund);
				break;
				}
				else
				{
					cout << "I'm sorry, this item is sold out.\n";
					break;
				}
			}
			case 6:
			{
                if (concession.getNumJersey() > 0)
				{
				cout << "\nHow many jerseys would you like to sell? (Current inventory: " << concession.getNumJersey() << " )\n";
				cin >> numToSell;

				int setJersey = concession.getNumJersey() - numToSell;
				concession.setNumJersey(setJersey);

				int setSales = concession.getSales() - (concession.getPriceJersey() * numToSell);
				concession.setSales(setSales);

				char refund = 'n';
				account.calculateCashOnHandAndDebt(numToSell * concession.getPriceJersey(), refund);
				break;
				}
				else
				{
					cout << "I'm sorry, this item is sold out.\n";
					break;
				}
			}
		}
		cout << "\nWould you like to sell more items <y/n>? ";
		cin >> option;
	}
}

/// Order new concession items to add to inventory
void orderNewInventory(Concession& concession, Bank& account)
{
	char option = 'y';
	int item = 0;
	while (option != 'n')
	{
		int numToOrder = 0;
		cout << "\n1. Hot Dogs \n2. Peanuts \n3. Burgers \n4. Soft Drinks \n5. Beer \n6. Jerseys"
		     << "\n\nChoose an item to order more inventory: ";
		cin >> item;
		switch (item)
		{
			case 1:
			{
				cout << "\nHow many hot dogs would you like to order? (Current inventory: " << concession.getNumHotDog() << " )\n";
				cin >> numToOrder;

                int setHD = concession.getNumHotDog() + numToOrder;
                concession.setNumHotDog(setHD);
				char refund = 'n';
				account.calculateCashOnHandAndDebt(-(numToOrder * (concession.getPriceHotDog()/2.0)), refund);
				break;
			}
			case 2:
			{
				cout << "\nHow many peanuts would you like to order? (Current inventory: " << concession.getNumPeanuts() << " )\n";
				cin >> numToOrder;

				int setPeanut = concession.getNumPeanuts() + numToOrder;
                concession.setNumPeanuts(setPeanut);
				char refund = 'n';
				account.calculateCashOnHandAndDebt(-(numToOrder * (concession.getPricePeanuts()/2.0)), refund);
				break;
			}
			case 3:
			{
				cout << "\nHow many burgers would you like to order? (Current inventory: " << concession.getNumBurgers() << " )\n";
				cin >> numToOrder;

				int setBurger = concession.getNumBurgers() + numToOrder;
                concession.setNumBurgers(setBurger);
                char refund = 'n';
				account.calculateCashOnHandAndDebt(-(numToOrder * (concession.getPriceBurgers()/2.0)), refund);
				break;
			}
			case 4:
			{
				cout << "\nHow many soft drinks would you like to order? (Current inventory: " << concession.getNumDrinks() << " )\n";
				cin >> numToOrder;

				int setDrink = concession.getNumDrinks() + numToOrder;
                concession.setNumDrinks(setDrink);
                char refund = 'n';
				account.calculateCashOnHandAndDebt(-(numToOrder * (concession.getPriceDrinks()/2.0)), refund);
				break;
			}
			case 5:
			{
				cout << "\nHow many beers would you like to order? (Current inventory: " << concession.getNumBeer() << " )\n";
				cin >> numToOrder;

				int setBeer = concession.getNumBeer() + numToOrder;
                concession.setNumBeer(setBeer);
                char refund = 'n';
				account.calculateCashOnHandAndDebt(-(numToOrder * (concession.getPriceBeer()/2.0)), refund);
				break;
			}
			case 6:
			{
				cout << "\nHow many jerseys would you like to order? (Current inventory: " << concession.getNumJersey() << " )\n";
				cin >> numToOrder;

				int setJersey = concession.getNumJersey() + numToOrder;
                concession.setNumJersey(setJersey);
                char refund = 'n';
				account.calculateCashOnHandAndDebt(-(numToOrder * (concession.getPriceJersey()/2.0)), refund);
				break;
			}
		}
		cout << "\nThank you, this inventory has been ordered. Would you like to order more inventory <y/n>? ";
		cin >> option;
	}
}
