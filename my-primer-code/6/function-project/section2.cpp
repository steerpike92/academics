#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <ctime>
#include <array>

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

bool is_empty(const std::string &s) { return s.empty(); }

void Problem_16()
{
	std::string s{ "not empty" };
	std::string s2;

	std::cout << is_empty(s) << std::endl;
	std::cout << is_empty(s2) << std::endl;
	std::cout << is_empty("") << std::endl;

}

bool HasCapital(const std::string &s) 
{
	for (auto c : s) {
		if (isupper(c)) {
			return true;
		}
	}
	return false;
}

void MakeLower(std::string &s)
{
	for (auto &c : s) {
		if (isupper(c)) {
			c = tolower(c);
		}
	}
}

void Problem_17()
{
	std::string ls = "a lowercase string";
	std::string us = "A sTrInG wItH uPpEr CaSe LeTteRs";

	std::cout << HasCapital(ls) << " " << HasCapital(us) << std::endl;

	if (HasCapital(us)) {
		MakeLower(us);
	}
	std::cout << us << std::endl;
}

int Sum(const std::vector<int> &cvec)
{
	int sum{ 0 };
	for (auto val : cvec) {
		sum += val;
	}
	return sum;
}

void Problem_19()
{
	std::vector<int> vec(10, 2);
	int sum = Sum(vec);
	std::cout << sum << std::endl;
}

void ArrayShenanigans()
{
	/*
	print(&i);	//okay, &i has type int*
	print(j);	//okay, j converted to &j[0]


	Functions ordinarily don't know the dimensions of the array they are given

		Tactic 1, Using a marker :
	remember the null character at the end of c style strings ?
		like that.

		Tactic 2, Using the STL conventions :
	Pass in a pointer to the first element and one past the end.
		i.e.
		DoSomething(const vector<T>::iterator begin, const vector<T>::iterator end);
	DoSomething(const int *begin, const int *end);

	Tactic 3, Explicitly pass in a size parameter :
	void print(cont int ia[], size_t size) {
		for (size_t i = 0; i != size, ++i) {
			cout << ia[i] << endl;
		}
	}


	Another tactic is to pass a reference to an array
		void print(int(&arr)[10]) {
		for (auto elem : arr) std::cout << elem << std::endl;
	}

	note that the parentheses around(&arr) are necessary
		int &arr[10] reads:
	(int&)arr[10], which is an array of references and an error

	*/
}

void SwapPtrs(int *(&p1), int *(&p2))
{
	int *temp = p1;
	p1 = p2;
	p2 = temp;
}

template <class T>
void PSwapPtrs(T **pp1, T **pp2)
{
	T *pt = *pp1;
	*pp1 = *pp2;
	*pp2 = pt;
}


void Problem_22()
{
	int i1 = 10, i2 = 20;
	int *p1 = &i1, *p2 = &i2;
	
	std::cout << *p1 << " " << *p2 << std::endl;
	std::cout << p1 << " " << p2 << std::endl;

	SwapPtrs(p1, p2);

	std::cout << *p1 << " " << *p2 << std::endl;
	std::cout << p1 << " " << p2 << std::endl;

	PSwapPtrs(&p1, &p2);

	std::cout << *p1 << " " << *p2 << std::endl;
	std::cout << p1 << " " << p2 << std::endl;
}

void CStrPrint(const char* const c_str)
{
	for (auto c = c_str; *c != '\0'; ++c) {
		std::cout << *c;
	}
	std::cout<<std::endl;
}

template<class T>
void CppPrint(const T *, const T *, char buff = '\0');

template<class T>
void CppPrint(const T *begin, const T *end, char buff)
{
	for (auto it = begin; it != end; ++it) {
		std::cout << *it;
		if (buff) std::cout << buff;
	}
	std::cout<<std::endl;
}

template<class T>
void SizePrint(const T *, size_t, char buff ='\0');

template<class T>
void SizePrint(const T *arr, size_t size, char buff)
{
	for (size_t i{ 0 }; i!=size; ++i) {
		std::cout << arr[i];
		if (buff) std::cout << buff;
	}
	std::cout << std::endl;
}

void Problem_23()
{
	const char carr[]{ "I'm a dumb c_string" };
	const int iarr[]{ 1, 53, 10 ,50, 3929 };
	//CStrPrint(carr);
	CStrPrint("I'm literally a literal");

	//CppPrint(std::begin(carr), std::end(carr));
	//CppPrint(std::begin(iarr), std::end(iarr), ' ');

	//SizePrint(carr, std::size(carr));
	//SizePrint(iarr, std::size(iarr),'\n');

}

void ReadErr(std::initializer_list<std::string> errors)
{
	for (auto s : errors){
		std::cout << s << std::endl;
	}
}

void VaryingParameters()
{
	/*std::cout 
		<< "We can take an unknown number of arguments using an initializer_list parameter "
		"an initializer_list is a library type that represents an array of values of the specified "
		"type."
		<< std::endl;*/

	std::string s{ "help im an error" };
	std::initializer_list<std::string> ilist {s};
	ReadErr(ilist);
	
	//it can be better than a vector because it has fixed size and thus no dynamic memory requirement
}

template<class T>
T SumArr(const T *const arr, size_t size)
{
	T sum{};
	for (size_t i{ 0 }; i != size; ++i) {
		sum += arr[i];
	}
	return sum;
}

template<class T, size_t N>
T SumStdArr(const std::array<T, N> arr)
{
	T sum{};
	for (auto i : arr) {
		sum += i;
	}
	return sum;
}

template<class T>
T SumList(const std::initializer_list<T> TList)
{
	T sum{};
	for (auto t : TList) {
		sum += t;
	}
	return sum;
}

template<class T>
T SumVector(const std::vector<T> TVec)
{
	T sum{};
	for (auto t : TVec) {
		sum += t;
	}
	return sum;
}

void Problem_27()
{
	constexpr int iterations{ 10000000 };

	clock_t tic{}, toc{};


	std::vector<int> result_store0(iterations);
	tic = clock();
	int arr[10]{ 0,1,2,3,4,5,6,7,8,9 };
	for (int i{ 0 }; i < iterations; ++i) {
		arr[0] = i;
		result_store0[i] = SumArr(arr,10);
	}
	toc = clock();
	std::cout << toc - tic << std::endl;

	std::vector<int> result_store3(iterations);
	tic = clock();
	std::array<int, 10> std_arr{ 0,1,2,3,4,5,6,7,8,9 };
	for (int i{ 0 }; i < iterations; ++i) {
		std_arr[0] = i;
		result_store3[i] = SumStdArr<int, 10>(std_arr);
	}
	toc = clock();
	std::cout << toc - tic << std::endl;


	std::vector<int> result_store1(iterations);
	tic = clock();
	std::initializer_list<int> ilist;
	for (int i{ 0 }; i < iterations; ++i) {
		ilist={ i,1,2,3,4,5,6,7,8,9 };
		result_store1[i]=SumList(ilist);
	}
	toc = clock();
	std::cout << toc - tic << std::endl;

	std::vector<int> result_store2(iterations);
	tic = clock();
	std::vector<int> ivec{ 0,1,2,3,4,5,6,7,8,9 };
	for (int i{ 0 }; i < iterations; ++i) {
		ivec[0] = i;
		result_store2[i]=SumVector(ivec);
	}
	toc = clock();
	std::cout << toc - tic << std::endl;

	


	//initializer lists and arrays are about 10x faster than vectors
}

void Section_2()
{
	//PtrSwap();
	//Problem_11();
	//Problem_12();
	//Problem_16();
	//Problem_17();
	//Problem_19();
	//ArrayShenanigans();
	//Problem_22();
	//Problem_23();
	//VaryingParameters();
	Problem_27();


}
