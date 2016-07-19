#include <iostream>
#include <string>
#include <vector>



typedef std::pair<std::string, bool> AugmentedType;

//typedef std::map<const ElementType, double> ElementPropertyMap;


int main() {


	std::vector<AugmentedType> augVector;

	AugmentedType augString;
	
	augString.first = "hello "; augString.second = true;
	augVector.push_back(augString);

	augString.first = "stupid "; augString.second = false;
	augVector.push_back(augString);

	augString.first = "world\n"; augString.second = true;
	augVector.push_back(augString);


	for (AugmentedType &augStr : augVector) {
		if(augStr.second) std::cout << augStr.first;
	}

	

	system("pause");
	return 0;
}

