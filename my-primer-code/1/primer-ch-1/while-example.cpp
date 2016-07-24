#include "header.h"
#include <iostream>



void WhileExample() {

	int start, end;

	std::cout << "Enter two integers: ";
	std::cin >> start >> end;

	int increment;
	if (start > end) { 
		increment = -1; 
		end--;
	}
	else {
		increment = 1;
		end++;
	}

	int n=start;

	//	While : tests condition (a bool)
	//	if condition is true, it executes the while body, i.e. a block { ... }
	//	and then tests the condition again

	while (n != end) {
		std::cout << n << "\n";
		n += increment;
	}
}