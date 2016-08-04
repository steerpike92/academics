#pragma once
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <math.h>
#include "money.h"
//8/3/2016


class SalesItem
{
	friend std::ostream& operator<<(std::ostream& out, const SalesItem& item);
	friend std::istream& operator>>(std::istream& in, SalesItem& item);

	int units_sold = 0;
	Money price;
	Money item_revenue;
	Money average_price;
public:
	std::string name;


	SalesItem():SalesItem("", 0, 0) {}
	SalesItem(std::string Name, int UnitsSold, Money Price);
	SalesItem(std::istream &is) : SalesItem() {is >> *this;}

	void calculateTotals();

	SalesItem operator += (SalesItem add_item);

};

std::istream&
operator>>(std::istream& in, SalesItem& item);

std::ostream&
operator<<(std::ostream &out, const SalesItem &item);