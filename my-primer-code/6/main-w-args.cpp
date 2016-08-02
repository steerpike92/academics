#include <iostream>


int main(int numOfArgs, char **arg_char_arrays)
{
	std::cout << numOfArgs << std::endl;

	for (int i = 0; i < numOfArgs; ++i) {
		std::cout << arg_char_arrays[i] << std::endl;
	}

	return 0;
}