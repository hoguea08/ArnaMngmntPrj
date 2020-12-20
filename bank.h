#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <fstream>

/// Bank class
class Bank
{
	private:

	double totalSales;
	double cashOnHand;
	double debt;

	public:

/// Bank constructor
	Bank()
	{
		totalSales = 0.0;
		cashOnHand = 0.0;
		debt = 0.0;
	}

	double getTotalSales() {return totalSales;}
	void setTotalSales(double total) {totalSales = total;}

	double getCashOnHand() {return cashOnHand;}
	void setCashOnHand(double cash) {cashOnHand = cash;}

	double getDebt() {return debt;}
	void setDebt(double d) {debt = d;}

	void readBankData(std::fstream&);
	void calculateCashOnHandAndDebt(double, char&);
};

    void bankOptions(Bank&);
    void printAcctInfo(Bank&);
    void addCashOnHand(Bank&, double);
    void payOffDebt(Bank&, double);

#endif // BANK_H_INCLUDED
