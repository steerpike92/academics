#include "header.h"

#include <iostream>
#include <string>

void StandardInOut() {

	std::cout << "Enter first and last name" << std::endl;

	//	std::cout : ostream object, i.e. standard output

	//	<< : output operator. operator must have an ostream object as lhv.
	//	<< returns its lhv, thus chaining is equivalent to:
	//	(std::cout << "Enter first and last name") << std::endl;

	//	"text"	: string literal, i.e. a string of characters

	//	std::endl : manipulator, flushes the stream and ends the line

	std::string first_name, last_name;

	std::cin >> first_name >> last_name;

	//	cin : istream object : standard input
	//	>> input operator

	std::cout << "Goodbye " << first_name << " " << last_name << std::endl;

}