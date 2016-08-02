//6.3	Return types and the return statment
//	8/2/2016

#include "main-header.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>

/*
//Return values work just like parameter initialization

//return value is used to initialize a temporary at the call site

//Can return a reference if it was given as an argument

//never return a pointer or reference to a local variable

//function call operator is left associative, so you can chain the result of a function call
*/

std::vector<int> VectorBuilder(size_t len)
{
	std::vector<int> ivec(len);
	for (size_t i{ 0 }; i < len; ++i) {
		ivec[i] = i*i;
	}
	return ivec;
}

void ResultChain()
{
	int end = *(VectorBuilder(10).rbegin());
	std::cout << end << std::endl;
}

/*
Return values are rvalues unless a reference is returned
*/

char &refVal(std::string &s, size_t pos)
{
	return s[pos];
}

void LReturn()
{
	std::string s{ "some boring string" };
	refVal(s, 4) = 'x';
	std::cout << s << std::endl;
}

template<class T>
void
VecRec(std::vector<T> &vec)
{
	if (vec.size() == 0) return;

	T tail = *(vec.rbegin());
	vec.pop_back();
	VecRec(vec);
	std::cout << tail << std::endl;
}

void Problem_33()
{
	std::vector<std::string> svec{ "why", "would", "you", "use", "a", "vector", "of", "strings" };
	auto svec2{ svec };
	VecRec(svec2);
}

std::array<int,10> ReturnsArr10Ints()
{
	std::array<int, 10> arr{};
	return arr;
}

void ArrayReturn()
{
	auto arr=ReturnsArr10Ints();
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << std::endl;
	}
}

void Section_3()
{
	//ResultChain();
	//LReturn();
	//Problem_33();
	ArrayReturn();
}

