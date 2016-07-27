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

	Money() :
		dollars(0),
		cents(0)
	{/*empty*/
	}

	Money(int Dollars, int Cents) :
		dollars(Dollars),
		cents(Cents)
	{
		CentOverflow();
	}

	Money(const Money &otherMoney) :
		dollars(otherMoney.dollars),
		cents(otherMoney.cents)
	{
		CentOverflow();
	}

	Money operator + (Money added)
	{
		Money returnedMoney = *this;
		returnedMoney.cents += (added.cents);
		returnedMoney.dollars += (added.dollars);
		returnedMoney.CentOverflow();
		return returnedMoney;
	}

	Money operator - (Money subtraced) const
	{
		Money returnedMoney = *this;
		returnedMoney.cents += subtraced.cents;
		returnedMoney.dollars += subtraced.dollars;
		returnedMoney.CentOverflow();
		return returnedMoney;
	}

	Money operator * (int multiplier)
	{
		Money returnedMoney = *this;
		returnedMoney.dollars *= multiplier;
		returnedMoney.cents *= multiplier;
		returnedMoney.CentOverflow();
		return returnedMoney;
	}

	Money operator * (double multiplier) const
	{
		Money returnedMoney = *this;
		double moneyDouble = dollars + cents / 100.0;
		moneyDouble *= multiplier;
		returnedMoney = moneyDouble;

		returnedMoney.CentOverflow();
		return returnedMoney;
	}

	Money operator / (double divider) const
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

	Money operator = (double moneyDouble)
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

	Money & operator= (const Money &) = default;

	/*Money operator = (Money otherMoney)
	{
		cents = otherMoney.cents;
		dollars = otherMoney.dollars;
		return *this;
	}*/

	Money operator = (int moneyInt)
	{
		dollars = moneyInt;
		return *this;
	}

	Money(int moneyInt) :
		dollars(moneyInt),
		cents(0)
	{/*empty*/
	}

	Money(double moneyDouble) :
		Money()
	{
		*this = moneyDouble;
	}

	void print()
	{

		std::cout << dollars << ".";
		int ucents = abs(cents);
		if (ucents < 10) {
			std::cout << "0";
		}
		std::cout << ucents;
	}


private:
	void CentOverflow()
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
};

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


struct SalesItem
{
	friend std::ostream& operator<<(std::ostream& out, const SalesItem& item);
	friend std::istream& operator>>(std::istream& in, SalesItem& item);

	std::string isbn;
	int units_sold=0;
	Money price;
	Money item_revenue;
	Money average_price;

	SalesItem()
	{/*empty*/}

	SalesItem(std::string ISBN, int UnitsSold, Money Price):
		isbn(ISBN),
		units_sold(UnitsSold),
		price(Price),
		item_revenue(price * units_sold),
		average_price(item_revenue /units_sold)
	{/*empty*/}

	void calculateTotals() {
		item_revenue=(price * units_sold);
		average_price=(item_revenue / units_sold);
	}

	SalesItem operator += (SalesItem add_item) 
	{
		if (isbn != add_item.isbn) {
			std::cout << "Error Item mismatch" << std::endl;
			return *this;
		}

		units_sold += add_item.units_sold;
		item_revenue = item_revenue + add_item.item_revenue;
		average_price = item_revenue / double(units_sold);
		return *this;
	}

	

};

std::istream&
operator>>(std::istream& in, SalesItem& item)
{
	in >> item.isbn;
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
	out << item.isbn << " ";
	out << item.units_sold << " ";
	out << item.item_revenue << " ";
	out << item.average_price << " ";
	return out;
}



class SalesData
{
	std::map<std::string, SalesItem> items_;

public:
	SalesData(){}
	void ProcessInput() 
	{
		items_.clear();
		SalesItem item;
		while (std::cin >> item) {
			if (items_.count(item.isbn) == 0) {
				items_[item.isbn] = item;
				std::cout << item << std::endl;
			}
			else {
				items_[item.isbn] += item;
				std::cout << item << std::endl;
			}
		}
	}

	void Print() const
	{
		std::cout<<std::endl;
		for (auto item : items_) {
			std::cout << item.second << std::endl;
		}
	}
	
};

void Exercises_2_40()
{
	//SalesItem book = SalesItem("12415-2314123-1313", 121, 62.994);
	//std::cout << book.isbn << " " << book.units_sold << " " << book.price <<std::endl;
	//SalesItem book2;
	//std::cout << book << std::endl;

	//std::cin >> book2;
	//std::cout << book2;
	
	SalesData data;
	data.ProcessInput();
	data.Print();

}

int main()
{
	Exercises_2_40();
	return 0;
}