//	2.4	const Qualifier
//	7/15/2016

#include <iostream>
#include "header.h"


int ArbitrarilyComplicatedExpression()
{
	return 420;
}

//const
void Notes_2_4_0() 
{
	const int buffer_size = 512;
	//buffer_size = 512; //error, buffer_size cannot be written to

	extern int a;//declaration : "there exists an object of this type and name" (can be done multiple times, variable must be defined here or elsewhere)
	int b;//definition : "create an object of this type, with this name" (must be done exactly once, also counts as declaration)
	int c = 2;//initialization : "definition + here's a value for the object (or values)"

	//need to initialize const variables. You can't change them later
	const int i = ArbitrarilyComplicatedExpression(); //fine, initialize at runtime
	const int j = 102; //fine, initialize at comple time
	//const int k; //error. k is uninitialized

	extern const int k; //fine, k is a const int which is initialized elsewhere
}

//must be outside block scope
//a_global_var must be defined as extern to be used elsewhere
extern const int a_global_var = ArbitrarilyComplicatedExpression(); 




//references to const
void Notes_2_4_1()
{
	//same as before, can't cange a reference to a const as the reference is the const object

	const int ci = 420;//cool
	const int &rci = ci;//cool

	//can't bind a non-const reference to a const object, as its still the same object
	//int &ri = rci; //not cool

	//"const reference" means "reference to const."  All refernces are perminantly bound, 
	//so in a sence, all references are const references (unlike pointers, which may change).


	//Importantly, we can however make a reference to const, based on a non-const object

	//i.e.
	int i = 420;//i is non-const
	const int &r1 = i;//r1 however is const

	//We can also make reference to const of rvalues for some reason
	const int &r2 = 42; //rvalue reference waaaaa!?
	const int &r3 = r1 * 2; //rvalue reference waaaa!?

	std::cout << i << " " << r1 << " " << r2 << " " << r3 << std::endl;

	//what happens is r1, r2 and r3 are bound to temporary const objects 

	//also, while r1 is a reference to const, i is still not const
	//so the value r1 might change, but we can't change it through r1
}

//Pointers and const
void Notes_2_4_2() 
{
	//can only store the address of a const object in a pointer to const
	const double dd = 32.21;
	const double * dd_ptr = &dd;

	//like references, we can store non-const objects in pointers to const

	double e = 3230.43;
	const double *e_ptr = &e;//can't change e through e_ptr


	//however unlike references, pointers are objects.
	//so pointers themselves can be const or non-const
	//const pointers remain pointed a fixed memory address
	//non-const pointers may change their address

	//const pointers indicated by putting const after the *. i.e.
	double f = 2232.242;
	double * const f_ptr = &f;
}


void Problem_2_28() 
{
	//defined int i. declared const pointer i_ptr;
	//int i, * const i_ptr;
	//okay because we can still change the value held at *i_ptr?
	//nvm not okay

	//what about?
	int i, *const i_ptr=&i;
	//yes that's okay

	//not okay because ic must be initialized
	//const int ic, &ir = ic;


	//okay becasue we can still assign ip to a const int maybe?
	const int *ip;
	//ya

	int oglaf = 192;

	ip = &oglaf;

	std::cout << ip << " " << *ip << std::endl;


}

//top level const
void Notes_2_4_3()
{
	//top level const refers to the object itself being const
	//low level const refers to the base object of a compound type being const

	//pointers can have each
	//references only can have low level const.
	//plain int's can just have top level

	//when you copy and object, top level const is ignored
	//(makes sense as copying does not change the object)

	//low level const is never ignored

}

void Notes_2_5()
{
	//auto


	//decltype


}


void Problem_2_35() 
{

	const int i=42;
	auto j = i;
	const auto &k = i;
	auto *p = &i;
	const auto j2 = i, &k2 = i;
}



int main()
{
	//Notes_2_4_0();
	//UseGlobalVar();//declared in header.h, defined in other-file.cpp. Uses a_global_var, which is initialized here
	//Notes_2_4_1();
	//Notes_2_4_2();
	//Problem_2_28();
	//Notes_2_4_3();
	Notes_2_5();
	//Problem_2_35();



	return 0;
}