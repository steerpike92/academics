#include <iostream>
#include <string>
#include <map>
#include "sales-item.h"
class SalesData
{
	std::map<std::string, SalesItem> items_;

public:
	SalesData() {}
	void ProcessInput()
	{
		items_.clear();
		SalesItem sales_item;
		while (std::cin >> sales_item) {
			if (items_.count(sales_item.name) == 0) {
				items_[sales_item.name] = sales_item;
				std::cout << sales_item << std::endl;
			}
			else {
				items_[sales_item.name] += sales_item;
				std::cout << sales_item << std::endl;
			}
		}
	}

	void Print() const
	{
		std::cout << std::endl;
		for (auto const sales_item : items_) {
			std::cout << sales_item.second << std::endl;
		}
	}

};