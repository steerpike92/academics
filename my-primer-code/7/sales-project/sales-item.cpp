#include "sales-item.h"


Money::Money() :
	dollars(0),
	cents(0)
{/*empty*/
}

Money::Money(int Dollars, int Cents) :
	dollars(Dollars),
	cents(Cents)
{
	CentOverflow();
}

Money::Money(const Money &otherMoney) :
	dollars(otherMoney.dollars),
	cents(otherMoney.cents)
{
	CentOverflow();
}

Money Money::operator + (Money added)
{
	Money returnedMoney = *this;
	returnedMoney.cents += (added.cents);
	returnedMoney.dollars += (added.dollars);
	returnedMoney.CentOverflow();
	return returnedMoney;
}

Money Money::operator - (Money subtraced) const
{
	Money returnedMoney = *this;
	returnedMoney.cents += subtraced.cents;
	returnedMoney.dollars += subtraced.dollars;
	returnedMoney.CentOverflow();
	return returnedMoney;
}

Money Money::operator * (int multiplier)
{
	Money returnedMoney = *this;
	returnedMoney.dollars *= multiplier;
	returnedMoney.cents *= multiplier;
	returnedMoney.CentOverflow();
	return returnedMoney;
}

Money Money::operator * (double multiplier) const
{
	Money returnedMoney = *this;
	double moneyDouble = dollars + cents / 100.0;
	moneyDouble *= multiplier;
	returnedMoney = moneyDouble;

	returnedMoney.CentOverflow();
	return returnedMoney;
}

Money Money::operator / (double divider) const
{
	Money returnedMoney = *this;
	if (divider == 0) {
		std::cout << "Error: divide by zero" << std::endl;
		return *this;
	}
	double moneyDouble = dollars + cents / 100.0;
	moneyDouble /= divider;
	returnedMoney = moneyDouble;

	returnedMoney.CentOverflow();
	return returnedMoney;
}

Money Money::operator = (double moneyDouble)
{
	if (moneyDouble >= 0) {
		dollars = int(moneyDouble);
		cents = round(100.0 * (moneyDouble - dollars));
	}
	else {
		dollars = int(moneyDouble) + 1;
		cents = round(100.0 * (moneyDouble - dollars));
	}
	CentOverflow();
	return *this;
}

Money & Money::operator= (const Money &) = default;

Money Money::operator = (int moneyInt)
{
	dollars = moneyInt;
	return *this;
}

Money::Money(int moneyInt) :
	dollars(moneyInt),
	cents(0)
{/*empty*/
}

Money::Money(double moneyDouble) :
	Money()
{
	*this = moneyDouble;
}

void Money::print()
{

	std::cout << dollars << ".";
	int ucents = abs(cents);
	if (ucents < 10) {
		std::cout << "0";
	}
	std::cout << ucents;
}



void Money::CentOverflow()
{
	if (cents >= 100) {
		dollars += cents / 100;
		cents %= 100;
	}
	else if (cents <= -100) {
		dollars += (cents / 100);//actually always subtracts
		cents %= 100;
	}
}

std::ostream&
operator<<(std::ostream& out, const Money& money)
{
out << money.dollars << ".";
int ucents = abs(money.cents);
if (ucents < 10) {
	out << "0";
}
out << ucents;
return out;
}



SalesItem::SalesItem() :
	name{},
	units_sold{},
	price{},
	item_revenue{},
	average_price{}
{/*empty*/
}

SalesItem::SalesItem(std::string Name, int UnitsSold, Money Price) :
	name(Name),
	units_sold(UnitsSold),
	price(Price),
	item_revenue(price * units_sold),
	average_price(item_revenue / units_sold)
{/*empty*/
}

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
	in >> item.name;
	in >> item.units_sold;

	double moneyDouble;
	in >> moneyDouble;
	item.price = moneyDouble;

	item.calculateTotals();

	return in;
}

std::ostream&
operator<<(std::ostream &out, const SalesItem &item)
{
	out << item.name << " ";
	out << item.units_sold << " ";
	out << item.item_revenue << " ";
	out << item.average_price << " ";
	return out;
}