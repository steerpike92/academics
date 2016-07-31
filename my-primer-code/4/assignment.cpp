//4.4 	Assignment Operators
//	7/30/2016

#include<iostream>

/*
assignment must have a left hand modifiable Lvalue

Legal, but not assignment:
int i = 0, j=12, k=11;	//initializations, not assignment
const int ci = i;	//initializations, not assignment

Illegal
1024 = k;		//literals are rvlaues
i + j = k;		//expression results are rvalues
ci = k;			//ci is not modifiable

Legal
k=0;
k=24141.21	//legal, but truncated to int


Assignment is right associative
int ival, jval;

ival = jval = 1;

same as:
jval = 1;
ival = jval;



Assignment has low precedence,
Relational operators have higher precedence, so if you want them to
Look at the result of assignment use paretheses


*/


int main()
{


	return 0;
}
