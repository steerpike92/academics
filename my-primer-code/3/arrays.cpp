//3.5	Arrays
//	7/29/16

#include <iostream>
#include <string>
#include <vector>

void ArrayInit()
{
	const int size = 10;	//must be const
	constexpr int sz = 141;
	int iarr[size];		//array of size ints defined
	int *parr[sz];		//array of size pointers to int defined
	
	int list_init1[] = { 1, 4, 61};	//explicit initialization, size deduced
	int list_init2[3] = { 1, 5, 2 };
}

void CharArray()
{
	char a1[] = { 'C', '+', '+' };		//no null
	char a2[] = { 'C', '+', '+', '\0' };	//explicit null
	char a3[] = "c++";			//null tacked on
	//char a4[3] = "c++";			//error, no room for '\0'
}

void SpookyArrays()
{
	//not actually spooky
	int arr[10];
	//arrays are objects and hold objects

	int *ptrs[10];		//fine, array of 10 ptrs to int
	//int &refs[10];	//error, refs aren't objects
	int(*Parray)[10] = &arr;//fine,... points to an array of 10 ints
	int(&arrRef)[10] = arr;	//fine.... reference to an array of 10 ints

	//read inside out

	// a (modifier, to)

	//array of 10...
	
	//of base 

	int *(&arry)[10] = ptrs;//so that's... a reference, to ptrs

}

constexpr size_t txt_size()
{
	return sizeof(int);
}

const size_t bufsize = 1212;

void Problem_27()
{
	int ia[txt_size()];
	int ia1[bufsize];
	int ia2[4 * 7 + 123];
	
}

std::string sa[4];
int ia[4];

void Problem_28()
{
	std::string sa1[4];
	int ia1[4];

	/*for (int i = 0; i < 4; i++) {
		std::cout << sa[i] << std::endl;
	}*/
	for (int i = 0; i < 4; i++) {
		std::cout << ia[i] << std::endl;
	}
	/*for (int i = 0; i < 4; i++) {
		std::cout << sa1[i] << std::endl;
	}
	for (int i = 0; i < 4; i++) {
		std::cout << ia1[i] << std::endl;
	}*/

	//strings always initialize zero

	//variables outside of function scope also initialize zero
	
}

void RageBased()
{
	int arr[5];

	for (auto &i : arr) {
		std::cin >> i;
	}
	std::cout << std::endl;
	for (auto const i : arr) {
		std::cout << i << std::endl;
	}
}

void ArrBegEnd()
{
	int arr[5];

	for (auto it = std::begin(arr); it != std::end(arr);++it) {
		std::cin >> *it;
	}
	std::cout << std::endl;

	for (auto it = std::begin(arr); it != std::end(arr); ++it) {
		std::cout << *it << std::endl;
	}
}

void PtrsAndSubscripts()
{
	int arr[]{ 1,5,6,61 };
	int *p = arr;	//equivalent to int *p=&arr[0];
	auto a = arr[2];
	auto b = *(p + 2);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	auto c = &arr[2];
	auto d = c[-2];

	std::cout << d << std::endl;
}

void VectorFromArray()
{
	int arr[]{ 42,5151,1262,112,5552152 };
	std::vector<int> ivec(std::begin(arr), std::end(arr));

	for (auto i : ivec) {
		std::cout << i << std::endl;
	}
}

int main()
{
	//ArrayInit();
	//CharArray();
	
	//Arrays forbid copy and assignment
	// int a[] = {0, 12, 42};	//okay
	// int a2[] = a;		//error, no copy construction
	// a2 = a			//error, no assignment

	//Problem_27();
	//Problem_28();

	//Arrays also support range based for loops
	//RageBased();

	//also now have begin and end
	//ArrBegEnd();

	//PtrsAndSubscripts();

	VectorFromArray();

	return 0;
}