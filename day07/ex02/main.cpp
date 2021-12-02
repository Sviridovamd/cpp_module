#include "Array.hpp"

#define MAX_VAL 750
#define MY_VAL 13

int main()
{
	Array<int> original(MY_VAL);
	std::cout << "Original Array" << std::endl;
	int i = 0;
	for (; i < MY_VAL; i++)
		original[i] = i;
	std::cout << original << std::endl;
	std::cout << "Size of Original Array:" << std::endl;
	std::cout << original.size() << std::endl;
	try
	{
		std::cout << "Let's try to take a non-existent element from Original Array:" << i + 1 << std::endl;
		std::cout << original[i + 1] << std:: endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

		std::cout << "Copying Original Array to Copy Array..." << std::endl;
		const Array<int>& copy(original);
		std::cout << "Copy Array before changes" << std::endl;
		std::cout << copy << std::endl;
		for (int c = 0; c < i - 1; c++)
			copy[c] *= i;
		std::cout << "New Copy Array" << std::endl;
		std::cout << copy << std::endl;
		std::cout << " Original Array after Copy Array has been changed" << std::endl;
		std::cout << original << std::endl;

	{
		Array<int> numbers(MAX_VAL);
				std::cout << numbers << std::endl;
		int *mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++) {
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
			std::cout << numbers << std::endl;
			std::cout << *mirror << std::endl;
		}
		//SCOPE
		{
			const Array<int>& tmp = numbers;
			std::cout << tmp << std::endl;
//			const Array<int>& test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++) {
			if (mirror[i] != numbers[i]) {
				std::cout << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try {
			numbers[-2] = 0;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}
		try {
			numbers[MAX_VAL] = 0;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++) {
			numbers[i] = rand();
		}
		delete[] mirror;//
	}


	return 0;
}