//3.5	Arrays
//	7/29/16

#include <iostream>
#include <string>

constexpr int determiner()
{
	int i = 4;
	int r = i*i;
	return r;
}

void ArrayInit()
{
	const int size = 10;	//must be const
	constexpr int sz = determiner();
	int iarr[size];		//array of size ints defined
	int *parr[sz];		//array of size pointers to int defined
	
	int list_init1[] = { 1, 4, 61};	//explicit initialization, size deduced
	int list_init2[3] = { 1, 5, 2 };


	
	
}


int main()
{
	ArrayInit();
	return 0;
}