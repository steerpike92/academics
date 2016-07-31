//4.1	expression fundamentals
//	7/30/2016

#include <iostream>
#include <vector>


int f1() {return 121;}
int f2() {return 11;}

int glob = 1;
int g1() { glob = glob * 5; return glob; }
int g2() { glob = glob - 1; return glob; }

void Basic()
{
	int i{ 1 }, j{ 4 }, k{ 0 };
	
	//Unary operator: acts on one operand
	//==============
	++i;		//++ acts on i;
	//-j;		//unary minus, returns negated r value.
	//Binary operator: acts on two operands
	//===============
	//i + j;	//+ acts on i and j
	//function operator: (), acts on unlimited operators

	
	//Precedence and Associativity
	//============================
	//precedence determines how expressions with more than one operator group the operands

	k= j + i * i;
	//std::cout << k << std::endl;
	// * has greater precedence so groups (i*i) together first, then applies +
	// = has lowest precedence
	//i.e. this is equivalent to
	k = (j + (i*i));
	//std::cout << k << std::endl;

	//can use ( ) to override precedence

	//associativity determines how operators of the same precedence group the operands
	k = i * j / i / j;
	//std::cout << k << std::endl;
	// * and / have same precedence, but both are left associative, so it goes from left to right
	k = (((i * j) / i) / j);
	//std::cout << k << std::endl;


	//order of evaluation
	//===================
	//Mostly unspecified
	i = f1() * f2();

	//which will happen first? f1() or f2()?
	//okay if pure functions with no side effects.

	//not good if they alter the same object!
	j = g1() * g2();// g1() and g2() both need and change glob!


	//Operand Conversions
	//===================
	//Types are often promoted to be used by operators
	//Small integral types (bool, char, short, ect) get promoted to int.
	//std::cout << (i == true) << std::endl;	//true promoted to int (i.e. 1 for true, 0 for false)
							//then compares i to 1, returns a bool 
	//Lvalues and Rvalues
	//===================

	//when we use an object as an Rvalue, we use its contents (value)
	//when we use an object as an Lvalue, we use its identity (its location in memory)

	//Lvalues can be converted to Rvalues by grabbing their contents
	//Rvalues cannot be used as Lvalues

	//Assignment (=) needs a left hand operand Lvalue and returns it's Left hand Lvalue
	//Address of (&) needs an Lvalue (right hand) and returns a pointer to it as an Rvalue
	//Dereference and Subscript (*, []) yeild Lvalues
	//++ and -- need Lvalues, the prefix version returns an Lvalue while the right hand version an Rvalue.
}

void Problem_2()
{
	std::vector<int> vec {4,14,616};

	auto a = *vec.begin();
	//highest precedence is .member operator
	//next highest is * dereference operator
	a = (*(vec.begin()));

	//======================

	auto b = *vec.begin() + 1;
	//order  . then * then +
	b = (*(vec.begin())) + 1;



}

int main()
{
	//Basic();
	//Problem_2();
	return 0;
}

