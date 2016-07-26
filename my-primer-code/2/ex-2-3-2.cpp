#include <iostream>
//	2.3.2 Pointers
//	7/25/2016


void Exercise_2_18() 
{
	int i = 10, *ptr = &i;
	int j = 5;
	std::cout << "i: " << i <<" j: "<<j<< " ptr to i: " << ptr << std::endl;

	ptr = &j;

	std::cout << "i: " << i << " j: " << j << " ptr to j: " << ptr << std::endl;
	
	*ptr = i;

	std::cout << "i: " << i << " j: " << j << " ptr to j: " << ptr << std::endl;
}

void Exercise_2_19() 
{
	std::cout << "A pointer is an object which stores the memory address of another object." << std::endl;
	std::cout << "A reference is not an object, but rather another name for an existing object." << std::endl;
	
	std::cout << "Both are compound types which must refer to their declared base type." << std::endl;

	std::cout << "Pointers are permitted to point to 1) An object, 2) Just past the end of an object (vector.end()?). 3) No object (nullptr), "
		"4) Some random place in memory that no longer holds the expected object (invalid)" << std::endl;

	std::cout << "The data pointed to by an invalid pointer can be just about anything. Writing to this data usually (hopefully) will cause an error "
		"and crash the program. Reading the data is often legal but will produce garbage." << std::endl;

	std::cout << "References are nice because they prevent the programmer from fucking up and reading from a garbage value. "
		"Whenever either references or pointers can be used, it is almost always best to use a reference." << std::endl;

	std::cout << "Pointers become necessary when manually allocating heap memory, and when employing polymorphism. "
		"Because it's easy to fuck up with pointers, it's often best to delegate heap allocation to library containers. "
		"You can still fuck up with library containers, but it's harder to do so." << std::endl;

	std::cout << "The most common need for references is when passing objects into and out of functions. Passing the object directly will usually create "
		"a copy. This is inefficient when passing large objects. It can also be quite nice to pass an object to a function which does work on the object."
		"Whenever you pass in an object and don't want work to be done on it (i.e. changed) pass it by const reference so it CANT be changed. "
		"(Unless of course they use const_cast, but that's not going to happen on accient)" << std::endl;

}

void Exercise_2_20()
{
	int i = 120;
	//double *d_ptr = &i; 
	//Error. Pointers want to point to a specific chunk of memory. 
	//A double *ptr will point to more bytes than an int *ptr
	//Thus dereferencing doesn't make sense.

	//std::cout << "i: " << i << " *d_ptr: " << *d_ptr << std::endl;
}

void Exercise_2_23()
{
	int i = 0; 
	int *ptr;

	//uninitialized pointer
	if (ptr)
		std::cout << "ptr not nullptr" << std::endl;
	else
		std::cout << "ptr is nullptr" << std::endl;

	//nullptr pointer
	ptr = nullptr;
	if (ptr)
		std::cout << "ptr not nullptr" << std::endl;
	else
		std::cout << "ptr is nullptr" << std::endl;

	//legit pointer
	ptr = &i;
	if (ptr)
		std::cout << "ptr not nullptr" << std::endl;
	else
		std::cout << "ptr is nullptr" << std::endl;

}

int main() 
{

	//Exercise_2_18();
	//Exercise_2_19();
	//Exercise_2_20();
	//Exercise_2_23();

	return 0;
}