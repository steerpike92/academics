#include "sales-item.h"

SalesItem::SalesItem(std::string Name, int UnitsSold, Money Price) :
	name(Name),
	units_sold(UnitsSold),
	price(Price),
	item_revenue(price * units_sold),
	average_price(item_revenue / units_sold)
{/*empty*/}

void SalesItem::calculateTotals() 
{
	item_revenue = (price * units_sold);
	average_price = (item_revenue / units_sold);
}

SalesItem SalesItem::operator += (SalesItem add_item)
{
	if (name != add_item.name) {
		std::cout << "Error Item mismatch" << std::endl;
		return *this;
	}

	units_sold += add_item.units_sold;
	item_revenue = item_revenue + add_item.item_revenue;
	average_price = item_revenue / double(units_sold);
	return *this;
}

std::istream&
operator>>(std::istream& in, SalesItem& item)
{
	do { std::getline(std::cin, item.name);
	} while (item.name.empty());

	in >> item.units_sold;
	in >> item.price;
	item.calculateTotals();
	return in;
}

std::ostream&
operator<<(std::ostream &out, const SalesItem &item)
{
	out << "Name	: "<<item.name << std::endl;
	out << "Units	: "<<item.units_sold << std::endl;
	out << "Tot Rev	: "<<item.item_revenue << std::endl;
	out << "Avg sale: "<<item.average_price << std::endl;
	return out;
}