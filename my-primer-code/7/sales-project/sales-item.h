#pragma once
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <math.h>
//my data structs
//7/27/2016

struct Money
{
	friend std::ostream& operator<<(std::ostream&, const Money& money);

	int dollars = 0, cents = 0;

	Money();

	Money(int Dollars, int Cents);

	Money(const Money &otherMoney);

	Money operator + (Money added);

	Money operator - (Money subtraced) const;

	Money operator * (int multiplier);

	Money operator * (double multiplier) const;

	Money operator / (double divider) const;

	Money operator = (double moneyDouble);

	Money & operator= (const Money &);

	Money operator = (int moneyInt);

	Money(int moneyInt);

	Money(double moneyDouble);

	void print();

private:
	void CentOverflow();
};

std::ostream&
operator<<(std::ostream& out, const Money& money);

class SalesItem
{
	int units_sold = 0;
	Money price;
	Money item_revenue;
	Money average_price;

public:
	std::string name;


	friend std::ostream& operator<<(std::ostream& out, const SalesItem& item);
	friend std::istream& operator>>(std::istream& in, SalesItem& item);

	SalesItem();

	SalesItem(std::string Name, int UnitsSold, Money Price);

	void calculateTotals();

	SalesItem operator += (SalesItem add_item);



};

std::istream&
operator>>(std::istream& in, SalesItem& item);

std::ostream&
operator<<(std::ostream &out, const SalesItem &item);