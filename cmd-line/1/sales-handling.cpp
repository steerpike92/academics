#include "header.h"
#include "Sales_item.h"
#include <iostream>
#include <map>
#include <string>

void SalesHandling()
{
	//Sales_item book1;
	//Sales_item book2;

	//std::cout << "Enter sales details: ";
	//std::cout << "ISBN, copies sold, sales price. \n";

	std::map<std::string,Sales_item> inventory;

	Sales_item temporaryBook;

	std::string isbn;

	while (std::cin >> temporaryBook) {

		isbn = temporaryBook.isbn();

		if (inventory.count(isbn) == 0) {
			inventory[isbn] = temporaryBook;
		}
		else {
			inventory[isbn]+=temporaryBook;
		}

	}

	//std::cin >> book1 >> book2;

	//std::cout << book1 << std::endl;
	//std::cout << book2 << std::endl;

	for (auto bookPair : inventory) {
		std::cout << bookPair.second << std::endl;
	}

}

