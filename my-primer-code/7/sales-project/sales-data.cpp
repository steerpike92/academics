#include "sales-data.h"

SalesData::SalesData() {}

void SalesData::ProcessInput()
{
	items_.clear();
	SalesItem sales_item;
	std::cout << "PROCESS INPUT\n\n";
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

void SalesData::Print() const
{
	std::cout << "\n\nPRINT TOTALS\n";
	std::cout << std::endl;
	for (auto const sales_item : items_) {
		std::cout << sales_item.second << std::endl;
	}
}
