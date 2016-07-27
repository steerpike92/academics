#include <iostream>
//Decltype
//7/27/2016

void Problem_2_36() 
{
	int a = 3, b = 4;
	decltype(a) c = a;
	decltype((b)) d = a;
	++c;
	++d;
}

void Problem_2_37() 
{
	int i = 1;
	//assignment yelds a reference type to lh operand. interestingly the expression in 
	//decltype() is examined for type, but not evaluated;
	decltype (i = 221) j = i;

	j++;

	std::cout << "j: " << j << " i: " << i << std::endl;

}

//Problem 2_38
//auto vs decltype

//auto looks at the object. Kills references/top level const
//decltype will match references and can be made to match references with (()) or an assignment. also retains top level const
//decltype is the only time a reference isn't just a synonym for the object underneith

//decltype can escape from references by using the referenc in an expression (but not assignment evidently)


void Experiment() 
{
	int i = 12;
	int &b = i;
	decltype(b + 0) r;
}

int main() 
{
	Problem_2_36();
	//Problem_2_37();
	Experiment();

	return 0;
}
