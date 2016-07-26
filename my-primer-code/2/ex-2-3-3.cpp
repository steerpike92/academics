#include <iostream>


void Notes()
{
	//can't make a pointer to refernce as it is not a object
	//this will just make a pointer to the object the reference ..references;
	int i = 10, &ri = i, *p1 = &i, *p2 = &ri;

	std::cout << "p1: " << p1 << ", p2: " << p2 << std::endl;
	//p1 and p2 are identical
}

void Exercise_2_25()
{
	int i, *ip = 0;
	//i is an uninitialized int.
	//ip is an initialized int pointer to nullptr.
	//remember that the * in the definition means "I'm a pointer," not "immediately dereference me"
	std::cout << "ip: " << ip << std::endl;

	ip = nullptr;
	std::cout << "ip: " << ip << std::endl;//same as before
}


int main() 
{
	//Notes();
	Exercise_2_25();

	return 0;
}