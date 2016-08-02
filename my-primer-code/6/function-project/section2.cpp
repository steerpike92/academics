#include <iostream>
#include <string>

template<class T>
void PSwap(T *a, T *b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template<class T>
void RSwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

void PtrSwap()
{
	int val1{ 42 }, val2{ 69 };
	std::cout << "val1 = " << val1 << " val2 = " << val2 << std::endl;
	PSwap(&val1, &val2);
	std::cout << "val1 = " << val1 << " val2 = " << val2 << std::endl;

	std::string s1{ "I'm string 1" }, s2{ "I'm string 2" };
	std::cout << "s1 = " << s1 << " s2 = " << s2 << std::endl;
	PSwap(&s1, &s2);
	std::cout << "s1 = " << s1 << " s2 = " << s2 << std::endl;

}

template<class T>
void Reset(T &t)
{
	T t2{};
	t = t2;
}

void Problem_11()
{
	int i = 92;
	std::cout << i << std::endl;
	Reset(i);
	std::cout << i << std::endl;

	std::string s = "Nonempty String";
	std::cout <<"s: "<< s << std::endl;
	Reset(s);
	std::cout <<"s: "<< s << std::endl;


}

void Problem_12()
{
	int val1{ 1111 }, val2{ 2222 };
	std::cout << "val1 = " << val1 << " val2 = " << val2 << std::endl;
	RSwap(val1, val2);
	std::cout << "val1 = " << val1 << " val2 = " << val2 << std::endl;

	std::string s1{ "I'm string 1" }, s2{ "I'm string 2" };
	std::cout << "s1 = " << s1 << " s2 = " << s2 << std::endl;
	RSwap(s1, s2);
	std::cout << "s1 = " << s1 << " s2 = " << s2 << std::endl;
}



void Section2()
{
	//PtrSwap();
	//Problem_11();
	//Problem_12();

}
