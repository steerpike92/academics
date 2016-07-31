//4.11	Type Conversions
//	7/31/2016
#include <iostream>
#include <string>

//void ArithmeticConversions()
//{
//	//int ival = int(3.5151 + 3);
//	//std::cout << ival << std::endl;
//
//	//Implicit conversions
//
//	//in expressions: smaller than int get promoted to int
//	//in conditions: nonbool are converted to bool
//	//in initializations the type is converted to the variable type
//	//in assignments the type is converted to the lhs
//	//in arithmetic and relational expressions, the types are converted to a common type
//	
//	//operands to an operator are converted to the widest type.
//
//	//char c = 'z';
//	//int i = 0;
//	//i += c;
//	//std::cout << i << std::endl;
//	
//
//	bool flag=true;
//	char cval='d';
//	short sval=-13;
//	unsigned short usval=15U;
//	int ival=-131;
//	unsigned uival=99U;
//	long lval=-928L;
//	unsigned long ulval=7838UL;
//	long long llval=-3485837LL;
//	unsigned long long ullval=93838383ULL;
//
//	float fval=343.471f;
//	double dval=1.003e33;
//	long double ldval = 3.3882187e202L;
//
//	auto v1 = 3.14159L + 'a';	//char(promotion) int -> long double
//	auto v2 = dval + ival;		//int -> double
//	auto v3 = dval + fval;		//float -> double
//	ival = dval;			//double (truncation) -> int
//	flag = dval;			//if dval is 0 flag is false, else true
//	auto v4 = cval + fval;		//cval (promotion) int -> float
//	auto v5 = cval + lval;		//cval to long
//}

void Problem_36()
{
	int i = 2;
	double d = 32.3201;

	i *= static_cast<int>(d);

	std::cout << i << std::endl;
}

void Problem_37()
{
	int i;
	double d = 0.3291;
	std::string s{ "I'm a dank string" };
	const std::string *ps= &s;
	std::string *ps2;
	
	void *pv = nullptr;

	pv = static_cast<void*>(const_cast<std::string*>(ps));

	ps2 = (std::string*) pv;
	
	const char *pc = (*ps2).c_str();

	//std::cout << *ps2 << std::endl;
	i = static_cast<int>(*pc);

	//std::cout << i << std::endl;

	pv = static_cast<void*>(&d);
	double *pd = static_cast<double*>(pv);
	d = *pd;

	std::cout << d << std::endl;

	i = 12;
	int j = 5;


	double slope = static_cast<double>(i) / j;

	std::cout << slope << std::endl;

}

int main()
{
	//ArithmeticConversions();
	//Problem_36();
	Problem_37();


	return 0;
}