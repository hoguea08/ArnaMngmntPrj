#ifndef PARKING_H_INCLUDED
#define PARKING_H_INCLUDED

#include "bank.h"
#include <iostream>
#include <iomanip>
#include <fstream>

/// Parking class

class Parking
{
private:
    int section;
    int space;
    double price;
    bool available;

public:
    Parking()
    {
        section = 0;
        space = 0;
        price = 0.0;
        available = false;
    }

    int getSection() {return section;}
	void setSection(int sec) {section = sec;}

	int getSpace() {return space;}
	void setSpace(int s) {space = s;}

	double getPrice() {return price;}
	void setPrice(double p) {price = p;}

	bool getAvailable() {return available;}
	void setAvailable(bool avail) {available = avail;}

	void readParkingData(std::fstream&);
	void changeAvailability();
};

    void parkingOptions(Parking*, int&, Bank&);
    void printParking(Parking*, int&);
    void printBySection(Parking*, int&);
    void sellParkingSpot(Parking*, int&, Bank&);
    void refundParkingSpot(Parking*, int&, Bank&);
    void changeParkingSpot(Parking*, int&);


#endif // PARKING_H_INCLUDED
