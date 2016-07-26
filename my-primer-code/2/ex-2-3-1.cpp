#include <iostream>


int main() {

	int i = 12.4, &r1 = i;
	double d = 0, &r2 = d;

	std::cout << i << std::endl;
	std::cout << d << std::endl;

	r2 = 3.14142;

	std::cout << d << std::endl;

	r2 = r1;

	std::cout << d << std::endl;

	i = r2;

	std::cout << i << std::endl;

	r1 = d;

	std::cout << i << std::endl;


	return 0;
}