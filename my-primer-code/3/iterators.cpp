//3.4	Iterators
//Date	7/29/2016

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

std::vector<std::string> ReadInputToSVec(bool lines)
{
	std::vector<std::string> svec;
	std::string current_string;

	if (lines) {
		while (std::getline(std::cin, current_string)) {
			svec.push_back(current_string);
		}
	}
	else {
		while (std::cin >> current_string) {
			svec.push_back(current_string);
		}
	}
	
	return svec;
}

void StrToUpper(std::string &str)
{
	for (auto it = str.begin(); it != str.end(); ++it) {
		*it = toupper(*it);
	}
}

void Problem_22()
{
	bool lines = true;
	auto svec = ReadInputToSVec(lines);
	
	if (svec.empty()) { std::cerr << "Empty Vector" << std::endl; return;  }
	
	StrToUpper(*svec.begin());

	for (auto cit = svec.cbegin(); cit != svec.cend(); ++cit){
		std::cout  << (*cit) << std::endl;
	}

}

void Problem_23()
{
	int N = 11;
	std::vector<int> ivec(N);
	for (int i = 0; i < N; ++i) {
		ivec[i] = i*i;
	}

	/*for (auto cit = ivec.cbegin(); cit!=ivec.cend()-1; ++cit) {
	int value = *cit + *(cit+1);
	std::cout << value << std::endl;
	}*/

	{
		auto crit = ivec.crbegin();
		auto cit = ivec.cbegin();

		while (cit != ivec.cend()) {
			int value = (*cit) + (*crit);
			std::cout << value << std::endl;

			++crit; ++cit;
		}
	}
	
}



std::vector<std::string>::iterator
BinarySearch(std::vector<std::string>::iterator begin, std::vector<std::string>::iterator end, std::string sought)
{
	
	std::vector<std::string>::iterator mid;
	mid= begin + (end - begin) / 2;

	if (sought == *mid) {
		return mid;
	}

	if (sought > *mid) {
		begin = mid + 1;
	}
	else if (sought < *mid) {
		end = mid;
	}
	return(BinarySearch(begin, end, sought));
}

void Problem_24()
{
	bool lines = false;
	auto svec{ ReadInputToSVec(lines) };

	std::sort(svec.begin(), svec.end());

	for (const auto &str : svec) {
		std::cout << str << std::endl;
	}

	std::cout << svec.begin()._Ptr << std::endl;

	auto begin = svec.begin();
	auto end = svec.end();
	std::string sought = "of";
	auto element = BinarySearch(begin, end, sought);
	
	if (element == end) {
		std::cout << sought << " not found" << std::endl;
	}
	else {
		std::cout << sought << " found at: "<< element._Ptr << std::endl;
	}

}

int main()
{
	//Problem_22();
	//Problem_23();
	Problem_24();


	return 0;
}
