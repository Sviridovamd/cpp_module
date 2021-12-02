#include <iostream>
#include "iter.hpp"

#define SIZE 3

int main()
{
	char *arr_c = createArray('l', SIZE);
	std::cout << "\t\tCHAR*********" << std::endl;
	std::cout << "first element arr_c:\t" << *arr_c << std::endl;
	iter(arr_c, SIZE, print<char>);
	delete arr_c;
	int *arr_i = createArray(42, SIZE);
	std::cout << "\t\tINT*********" << std::endl;
	std::cout << "first element arr_i:\t" << *arr_i << std::endl;
	iter(arr_i, SIZE, print<int>);
	delete arr_i;
	float *arr_f = createArray(4.2f, SIZE);
	std::cout << "\t\tFLOAT*********" << std::endl;
	std::cout << "first element arr_f:\t" << *arr_f << std::endl;
	iter(arr_f, SIZE, print<float>);
	delete arr_f;
	{
		std::cout << "****CHECKLIST****" << std::endl;
		Awesome tab2[5];
		int tab[] = {0, 1, 2, 3, 4};
		iter(tab, 5, print_a);
		iter(tab2, 5, print_a);
		return 0;
	}

}