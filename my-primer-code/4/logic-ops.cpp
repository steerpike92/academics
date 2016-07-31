//4.3	Logical and Relational Operators
//	7/30/2016
#include <iostream>



int main()
{	/*
	watch out for bools getting promoted to ints
	precedence:

	!	take bool return bool

	/////

	<
	<=
	>
	>=

	////

	==	return bool
	!=	

	////
		take bool, return bool
	&&	checks right iff left is true

	////
		take bool, return bool
	||	checks right iff left is false
	
	all return bool
	

	if(i < j < k)
	is really:
	if(  (i < j) < k  )

	(i < j) yields true or false, which is converted to 0 or 1
	so k is compared in size to 0 or 1...

	probably want:
	if(i<j && j<k)

	*/



	return 0;
}