#include "Sales_item.h"
#include <iostream>

void SalesHandling()
{
	Sales_item book;

	std::cout << "Enter sales details: ";

	std::cout << "ISBN, copies sold, sales price. \n";
	std::cin >> book;
	
	std::cout << book << std::endl;


}