#ifndef CONCESSION_H_INCLUDED
#define CONCESSION_H_INCLUDED

#include "bank.h"
#include <iostream>
#include <iomanip>
#include <fstream>

/// Concession class
class Concession
{
private:

	int numHotDog;
	double priceHotDog;

	int numPeanuts;
	double pricePeanuts;

	int numBurgers;
	double priceBurgers;

	int numDrinks;
	double priceDrinks;

	int numBeer;
	double priceBeer;

	int numJersey;
	double priceJersey;

	double sales;

	public:

	Concession()
	{
		numHotDog = 0;
		priceHotDog = 0.0;
		numPeanuts = 0;
		pricePeanuts = 0.0;
		numBurgers = 0;
		priceBurgers = 0.0;
		numDrinks = 0;
		priceDrinks = 0.0;
		numBeer = 0;
		priceBeer = 0.0;
		numJersey = 0;
		priceJersey = 0.0;
		sales = 0.0;
	}

	int getNumHotDog() {return numHotDog;}
	void setNumHotDog(int hotdog) {numHotDog = hotdog;}

	double getPriceHotDog() {return priceHotDog;}
	void setPriceHotDog(double hdPrice) {priceHotDog = hdPrice;}

	int getNumPeanuts() {return numPeanuts;}
	void setNumPeanuts(int peanut) {numPeanuts = peanut;}

	double getPricePeanuts() {return pricePeanuts;}
	void setPricePeanuts(double pPrice) {pricePeanuts = pPrice;}

	int getNumBurgers() {return numBurgers;}
	void setNumBurgers(int burger) {numBurgers = burger;}

	double getPriceBurgers() {return priceBurgers;}
	void setPriceBurgers(double bPrice) {priceBurgers = bPrice;}

	int getNumDrinks() {return numDrinks;}
	void setNumDrinks(int drink) {numDrinks = drink;}

	double getPriceDrinks() {return priceDrinks;}
	void setPriceDrinks(double dPrice) {priceDrinks = dPrice;}

	int getNumBeer() {return numBeer;}
	void setNumBeer(int beer) {numBeer = beer;}

	double getPriceBeer() {return priceBeer;}
	void setPriceBeer(double aPrice) {priceBeer = aPrice;}

	int getNumJersey() {return numJersey;}
	void setNumJersey(int jersey) {numJersey = jersey;}

	double getPriceJersey() {return priceJersey;}
	void setPriceJersey(double jPrice) {priceJersey = jPrice;}

	double getSales() {return sales;}
	void setSales(double s) {sales = s;}

    void readConcData(std::fstream&);
};

void concessionOptions(Concession&, Bank&);
void printConcessionInfo(Concession&);
void totalConcessionSales(Concession& concession);
void sellInventory(Concession&, Bank&);
void orderNewInventory(Concession&, Bank&);

#endif // CONCESSION_H_INCLUDED
