#include "money.h"

int CharToInt(char c)
{
	return static_cast<int>(c) - static_cast<int>('0');
}

std::ostream&
operator<<(std::ostream& out, const Money& money)
{
	if (money.dollars < 0 || money.cents < 0) {
		out << '-';
	}
	out <<'$'<< abs(money.dollars) << '.';
	unsigned ucents = abs(money.cents);
	if (ucents < 10) {
		out << '0';
	}
	out << ucents;
	return out;
}

std::istream&
operator>>(std::istream &in, Money &money)
{
	std::string in_str;
	in >> in_str;

	auto it = in_str.cbegin();
	const auto end = in_str.cend();

	if (it == end) { std::cout << "no money input" << std::endl; return in; }

	//sign
	int sign = 1;
	if (*it == '-') {
		sign = -1;
		++it;
	}

	if (*it == '$') {
		++it;
	}

	const auto beg = it;

	//read until end or decimal
	auto decimal = end;
	for (; it != end; ++it) {
		if (*it == '.') {
			decimal = it;
			break;
		}
		if (!isdigit(*it)) {
			std::cout << "not a digit"; return in;
		}
	}

	int dollars = 0;
	//read in dollars
	if (it != beg) {
		int order = 0;
		int digit = 0;
		do {
			--it;
			digit = CharToInt(*it);
			dollars += digit * static_cast<int>(pow(10, order));
			++order;
		} while (it != beg);
	}
	
	//read in cents
	int cents = 0;
	if (decimal != end) {
		it = decimal;
		it++;
		if (it != end) {
			cents = 10 * CharToInt(*it);
			++it;
			if(it != end) {
				cents += CharToInt(*it);
			}
		}
	}

	money.dollars = dollars*sign;
	money.cents = cents*sign;

	return in;
}

