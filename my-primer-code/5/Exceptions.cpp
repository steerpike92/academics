#include <iostream>
#include <string>


void ExceptionTest()
{

	bool success{ false };
	
	do {

		try {
			int i, j;
			std::cout << "Enter two ints: \n";
			std::cin >> i >> j;

			if (j == 0) {
				throw std::runtime_error("Can't divide by 0");
			}

			std::cout << i << "/" << j << " = " << i / j;

			success = true;
		}
		catch (std::runtime_error error) {
			std::cout << error.what() << std::endl;;
			std::cout << "Try again?: (y) or (n): ";
			std::string response;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cin >> response;
			char decision = response[0];

			if (decision == 'n') success = true;
			else success = false;
		}
	} while (!success);

	



}



int main()
{
	ExceptionTest();

	return 0;
}


