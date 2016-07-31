//4.2	Arithmetic Operators
//	7/30/2016
#include <iostream>
#include <string>

void Notes()
{
	
	int i{0}, j{0};
	i = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;

	j = ((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2);

	std::cout << i << " " << j << std::endl;

	//truncations of / operator always toward zero. 
	
	//% (remainder, modulus operator)

	//is always the same sign as the left hand operator

}

void Problem_5()
{
	int i = 0;
	//a
	i = -30 * 3 + 21 / 5;
	// -90 + 4 = -86;
	std::cout << i << std::endl;

	//d
	i = -30 / 3 * 21 % 4;
	// -10 * 21 % 4
	// -210 % 4
	// -2
	std::cout << i << std::endl;

}

bool Even(int i)
{
	return !(i % 2);
}

void Problem_6()
{
	int i = -12, j = -11;
	bool i_even = Even(i);
	bool j_even = Even(j);

	std::string i_result;
	if (i_even)	{ i_result = "even";}
	else		{ i_result = "odd"; }

	std::string j_result;
	if (j_even) { j_result = "even"; }
	else { j_result = "odd"; }
	
	std::cout << i<<" is " + i_result << std::endl;
	std::cout << j<< " is " + j_result << std::endl;
}

void Problem_7()
{
	//overflow
	//when an operation yields a result too large to be stored in the provided types

	
	int j = 1e+2;
	int i { j };

	for (int k = 0; k < 5; ++k) {
		std::cout << i << std::endl;
		i *= j;
	}

	std::cout<<"int max: " << INT_MAX << std::endl;
	
	long long i2{ j };

	for (int k = 0; k < 10; ++k) {
		std::cout << i2 << std::endl;
		i2 *= j;
	}

	j = 1e+6;

	long double i3 = j;
	for (int k = 0; k < 20; ++k) {
		std::cout << i3 << std::endl;
		i3 *= j;
	}



}

int main()
{
	//Notes();
	//Problem_5();
	//Problem_6();
	Problem_7();
	return 0;
}