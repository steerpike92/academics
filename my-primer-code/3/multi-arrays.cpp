//3.6	Multidimensional Arrays
//	7/29/2016
#include<iostream>


void Notes()
{
	const int rows = 4;
	const int row_len = 10;//or "cols" but thinking of it as row_len is closer to what's going on
	int i2d[rows][row_len] {/*inits to zero*/};
	//i2d is an array of size (rows). Each element is a (row_len) array. Of ints.

	for (auto &row : i2d) {//all but the innermost loop must be a reference to maintain 'array-ness'
	//(auto row : i2d) would have row be an int*, which you can't then iterate over
		for (auto val : row) {
			std::cout << val;
		}
		std::cout << std::endl;
	}

	/*int i1d[rows]{};

	for (decltype(i1d[0]) i : i1d) {
		std::cout << i;
	}*/

	

}

void Problem_43()
{

	const size_t rows = 4;
	const size_t row_len = 2;//or "cols" but thinking of it as row_len is closer to what's going on
	int i2d[rows][row_len]{ 
		{1, 2}, 
		{5, 6},
		{10, 11},
		{15, 16}
	};

	//No Type Help

	/*for (int(&row)[row_len] : i2d) {
		for (int val : row) {
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}*/

	/*for (size_t r = 0; r < rows; ++r) {
		for (size_t c = 0; c < row_len; ++c) {
			std::cout << i2d[r][c] << " ";
		}
		std::cout << std::endl;
	}*/

	/*for (int(*p)[row_len] = i2d; p != i2d + rows; ++p) {
		for (int *inner = *p; inner != *p + row_len; ++inner) {
			std::cout << *inner<<" ";
		}
		std::cout << std::endl;
	}*/


	
	




	




}

void Problem_44()
{
	const size_t rows = 4;
	const size_t row_len = 2;//or "cols" but thinking of it as row_len is closer to what's going on
	int i2d[rows][row_len]{
		{ 1, 2 },
		{ 5, 6 },
		{ 10, 11 },
		{ 15, 16 }
	};

	//type aliases

	using int_arr = int[row_len];

	/*for (int_arr &row : i2d) {
	for (int i : row) {
	std::cout << i << " ";
	}
	std::cout << std::endl;
	}*/

	/*
	for (int_arr *arr = i2d; arr != std::end(i2d); ++arr) {
	for (int *p = *arr; p != std::end(*arr); ++p ) {
	std::cout << *p << " ";
	}
	std::cout << std::endl;
	}*/
}


void Problem_45()
{
	constexpr size_t rows = 5;
	constexpr size_t cols = 4;
	constexpr size_t height = 3;
	int i3d[rows][cols][height]{};//zero init

	//full type help

	for (auto &row : i3d) {
		for (auto &col : row) {
			for (auto val : col) {
				std::cout << val << " ";
			}
			std::cout<< ", ";
		}
		std::cout << std::endl;
	}
}

int main() 
{
	//Notes();
	//Problem_43();
	//Problem_44();
	Problem_45();
	return 0;
}
