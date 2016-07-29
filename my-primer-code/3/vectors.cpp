//	Vectors:	3.3
//	Date:		7/28/2016

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using std::vector;
using std::string;

void VectorInit()
{
	//vector: collection of objects, all of which have the same type.
	//elements have associated index
	//a "container" as it "contains" other objects

	//vector is a class template.
	//the compiler creates functions and classes from templates using "instantiation". 
	//instantiation requires the desired type in brackets after the templates name. i.e.
	vector<double> v;	//vector of doubles named v

	v.push_back(1213.4);
	//std::cout << v.front() << std::endl;

	//note that "vector" is not a type. vector<type> is the type

	//vectors hold objects. references are not objects, and thus you can't have a vector of references

	vector<int> ivec;	//default initialized. empty vector of ints
	ivec.push_back(420);
	ivec.push_back(69);
	ivec.push_back(17);

	vector<int> ivec2(ivec);	//copy construction. ivec2 must have same type as ivec;
	auto ivec3(ivec);		//or..
	auto ivec4 = ivec;		//or..

	//list initializing

	vector<int> funny_numbers{ 420,69,13 };
	//vector<int> sillyNumbers(420,69,17); //error, use list initialization

	//specified number of elements
	vector<int> ivec5(10, -1);	//initializes with 10 -1's
	vector<string> svec(10, "daow! ");
	vector<string> svec2(20);	//20 empty strings


	//carful with () and {}

	vector<int> v1(10);	//10 int elements (initialized to zero)
	vector<int> v2{ 10 };	//one element that is 10
	vector<int> v3(10, 1);	//10 1's
	vector<int> v4{ 10,1 };	//a 10 and a 1

	//note that the comiler doesn't have to list initialize if it can't
	vector<string> wards1{ 12,"ey" };	//12 isn't a string, so reinterperets to 12 "ey"'s
	vector<string> wards2{ "ey" };		//1 "ey"
	vector<string> wards3{ 10 };		//10 empty strings

	

}

void AddElements()
{
	//vector member push_back:
	size_t i;
	size_t top = 1000000;

	auto tic = clock();
	vector<vector<string>> values;
	i = 0;
	while (i < top) {
		vector<string> subVec{ std::to_string(i) };
		values.push_back(subVec);
		i++;
	}
	auto toc = clock();
	std::cout << "Time: " << toc - tic << std::endl;


	tic = clock();
	vector<vector<string>> values2(top);
	i = 0;
	while (i < top) {
		vector<string> subVec{ std::to_string(i) };
		values2[i] = subVec;
		i++;
	}
	toc = clock();
	std::cout << "Time: " << toc - tic << std::endl;
}

void Problem_20()
{
	int N;
	std::cout << "Propose a vector size: ";
	std::cin >> N;
	vector<int> ivec(N);
	for (int i = 0; i < N; ++i) {
		ivec[i] = i*i;
	}

	/*for (int i = 0; i < N - 1; ++i) {
		int value = ivec[i] + ivec[i + 1];
		std::cout << value << std::endl;
	}*/

	for (int i = 0; i < N; ++i) {
		int value = ivec[i] + ivec[N - i - 1];
		std::cout << value << std::endl;
	}

}

int main() 
{
	//VectorInit();
	//AddElements();
	//Problem_20();

	return 0;
}