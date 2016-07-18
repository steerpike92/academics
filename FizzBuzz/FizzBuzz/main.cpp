#include <iostream>

int main() {


	bool suppress;
	for (int i = 0; i < 100; i++) {
		suppress = false;
		if (!(i % 3)) {
			std::cout << "fizz";
			suppress = true;
		}

		if (!(i % 5)) {
			std::cout << "buzz";
			suppress = true;
		}

		if (!suppress) std::cout << i;
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}