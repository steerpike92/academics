#pragma once
#include <iostream>
#include <string>
#include <cmath>

struct Money
{
	friend std::ostream& operator<<(std::ostream&, const Money& money);
	friend std::istream& operator>>(std::istream&, Money &money);

	int dollars = 0, cents = 0;

	Money() :
		dollars(0),
		cents(0)
	{/*empty*/}

	Money(int Dollars, int Cents) :
		dollars(Dollars),
		cents(Cents)
	{
		CentOverflow();
	}

	Money(const Money &otherMoney) :
		dollars(otherMoney.dollars),
		cents(otherMoney.cents)
	{/*empty*/}

	Money operator + (Money added)
	{
		Money returnedMoney = *this;
		returnedMoney.cents += (added.cents);
		returnedMoney.dollars += (added.dollars);
		returnedMoney.CentOverflow();
		return returnedMoney;
	}

	Money operator += (Money added)
	{
		*this = *this+ added;
	}

	Money operator - (Money subtraced) const
	{
		Money returnedMoney = *this;
		returnedMoney.cents += subtraced.cents;
		returnedMoney.dollars += subtraced.dollars;
		returnedMoney.CentOverflow();
		return returnedMoney;
	}

	Money operator -= (Money subtracted)
	{
		*this = *this- subtracted;
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
		dollars = int(moneyDouble);
		cents = static_cast<int>(round(100.0 * (moneyDouble - dollars)));
		return *this;
	}

	Money & operator= (const Money &) = default;

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

private:
	void CentOverflow()
	{
		if (abs(cents) >= 100) {
			dollars += cents / 100;
			cents %= 100;
		}
	}
};
