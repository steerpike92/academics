#pragma once
#include <iostream>
#include <string>
#include <map>
#include "sales-item.h"
class SalesData
{
	std::map<std::string, SalesItem> items_;

public:
	SalesData();
	void ProcessInput();
	void Print() const;
};