#include "header.h"
#include <iostream>
#include <string>

unsigned long long Factorial(unsigned int x)
{
	unsigned long long product = 1;

	for (; x > 1; --x) {
		product *= x;
	}
	return product;
}

void Problem_3()
{

	int x;
	std::cout << "Enter a positive integer: ";
	std::cin >> x;

	if (x < 1) { std::cout << "Not a positive integer"; return; }

	auto y = Factorial(x);

	std::cout << x << "! = " << y << std::endl;

}

unsigned CallCounter()
{
	static unsigned call_count = 0;
	return ++call_count;
}

void Problem_7()
{
	for (int i = 0; i < 23; ++i) {
		std::cout << CallCounter() << std::endl;
	}
}