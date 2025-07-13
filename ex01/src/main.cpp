#include "../includes/iter.hpp"


int main(void) {
	int			array_int[MAX_VAL];
	float		array_float[MAX_VAL];

//  Fill arrays
	for (int i = 0; i < MAX_VAL; i++) {
		array_int[i] = i;
		array_float[i] = i + (float)1 / (float)2;
	}

//  Print arrays
	std::cout << "PRINT VALUES" << std::endl;
	std::cout << "    INT" << std::endl;
	::iter(array_int, MAX_VAL, print);
	std::cout << "    FLOAT" << std::endl;
	::iter(array_float, MAX_VAL, print);
	std::cout << std::endl;

//  Add function
	::iter(array_int, MAX_VAL, add);
	::iter(array_float, MAX_VAL, add);

//  Print arrays
	std::cout << "PRINT VALUES" << std::endl;
	std::cout << "    INT" << std::endl;
	::iter(array_int, MAX_VAL, print);
	std::cout << "    FLOAT" << std::endl;
	::iter(array_float, MAX_VAL, print);
}
