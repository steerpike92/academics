//4.5 	Increment and Decrement Operators
//	7/30/2016

#include <iostream>
#include <vector>

/*
convenient shorthand for adding or subtracting 1
necessary for iterators, which often don't define arithmetic


post:
i ++
i --

pre:
++ i
-- i

both take lvalues. 
post returns origonal object as rvalue
pre returns updated object as lvalue

*/

void WithPtrs()
{
	std::vector<int> ivec{ 1,5,172,21,3, -12, 1, 9192 };

	auto it = ivec.begin();
	auto it_end = ivec.end();
	//print out values in vector up to but not including first negative value
	while (it != it_end && *it >= 0)
		std::cout << *it++ << std::endl;//dereferences it before the ++

	//never do an operation that changes an lvalue operand, and then use that operand multiple times in an expression
	//it = ivec.begin();
	//while (it != it_end && *it >= 0)
	//	*it = (*it++) * 10;

	//here if the left side is evaluated first, we get normal behavior
	//if the right side is evaluated first, it++ will increment it and the left side will derference one ahead
	//this is super fucky as it writes to unowned memory (as it does on my machine)

}

void MemberAccess()
{
	std::vector<int> ivec{ 124,151,121,5551 };

	auto it = ivec.begin();

	++*it;//dereferences then increments

	for (auto i : ivec)
		std::cout << i << std::endl;
}

int main()
{
	//WithPtrs();
	MemberAccess();
	return 0;
}
