#include <iostream>

struct NoDefault {
	int i;
	NoDefault(int I) :i(I) {}
};

struct A {
	NoDefault ndef;
};

int main()
{
	A;
	return 0;
}