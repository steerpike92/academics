#include <iostream>
#include <string>

int number;//gets 0 initialized
std::string empty;//default initialized

int main() {
	//int input_value;
	//std::cin >> input_value;
	
	//double wage{ 99999.99L };
	//std::cout << int(wage) << std::endl;

	std::cout << number << std::endl;
	std::cout << empty << std::endl;

	int number;//uninitialized
	std::string empty;//default initialized

	std::cout << number << std::endl;
	std::cout << empty << std::endl;

	return 0;
}