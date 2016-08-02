#include <iostream>
#include <string>
#include <vector>

void Problem_14()
{
	std::string current_word, current_repeated_word, max_repeated_word;
	size_t current_repititions{ 0 }, max_repititions{ 0 };

	while (std::cin >> current_word) {
		if (current_repeated_word == current_word) {
			++current_repititions;

			if (current_repititions > max_repititions) {
				max_repititions = current_repititions;
				max_repeated_word = current_word;
			}

		}
		else {
			current_repeated_word = current_word;
			current_repititions = 0;
		}
	}

	if (max_repititions == 0) {
		std::cout << "No word was repeated" << std::endl;
	}
	else {
		std::cout << "The word: " << max_repeated_word << " occured " << max_repititions+1 << " times in a row" << std::endl;
	}
}

void TradFor()
{
	std::vector<int> ivec (300000,1);
	
	//neat syntax I didn't know about
	unsigned long long sum{ 0 };

	for ( decltype(ivec.size()) index = 0, sz = ivec.size(); index < sz; ++index) {
		sum += index;
	}

	std::cout << "The sum of the indicies is: " << sum << std::endl;
	std::cout << "The average index is: " << sum / ivec.size() << std::endl;


}

void RangeFor()
{
	//for(declaration : expression)
	//	statement

	//expression must be a sequence with begin and end members that return iterators

	//if you want to write to the sequence USE REFERENCES

	std::vector<int> v{ 0,1,2,3,4,5,6,7,8,9 };

	//double each element in v
	for (auto &r : v) {
		r *= 2;
		std::cout << r << " ";
	}

	std::cout << std::endl;

	//defined in traditional for as:
	for (auto beg = v.begin(), end = v.end(); beg != end; ++beg) {
		auto &r = *beg;
		r *= 2;
		std::cout << r << " ";
	}



	//note that the end iterator is cached, so you can't change the size of the sequence here

	
}

bool ContinueCheck()
{
	bool response, response_valid;
	std::string entered;
	do {
		response = false;
		response_valid = false;

		// Ignore to the end of file
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Would you like to continue? enter 'y' or 'n': ";
		std::cin >> entered;

		switch (entered[0]) {
		case('Y') :
		case('y') :
			response = true;
			response_valid = true;
			break;
		case('N') :
		case('n') :
			response = false;
			response_valid = true;
			break;
		default :
			std::cout << "Not a valid response\n";
			response_valid = false;
		}


	} while (!response_valid);

	return response;
}

void DoWhile()
{
	//do
	//	statement
	//while (condition);

	//guaranteed to execute statement at least once

	//condition is outside the scope of the statment body
	//thus they must be declared before it

	bool response = false;
	do {
		int val1, val2;
		std::cout << "Enter two values: ";
		std::cin >> val1 >> val2;
		std::cout << "The sum of " << val1 << " and " << val2 << " is: " << val1 + val2 << std::endl << std::endl;
		
		response = ContinueCheck();

	} while (response);


}

int main()
{
	//Problem_14();
	//TradFor();
	//RangeFor();
	DoWhile();

	return 0;
}