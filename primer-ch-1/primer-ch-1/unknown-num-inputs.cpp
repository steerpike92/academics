#include "header.h"
#include <iostream>


void UnknownNumberOfInputs() {

	int input=0;
	int sum=0;

	std::cout << "Enter a slew of ints: ";

	while (std::cin >> input) { 
		// std::cin >> input evaluates false if it encounters an error (entering a string)
		// or you can indicate end of file by pressing Ctrl z
		sum += input;
	}

	std::cout << std::endl << "sum= " << sum << std::endl;


}