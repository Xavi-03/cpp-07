#include <iostream>
#include "../includes/Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	{
		std::cout << "    FLOAT" << std::endl;
		Array<float> arr(3);
		Array<float> arr2(3);
		(void)arr;
		arr[0] = 1.2;
		arr[1] = 2.2;
		arr[2] = 3.2;
		std::cout << arr[0] << std::endl;
		std::cout << arr[1] << std::endl;
		std::cout << arr[2] << std::endl;
		arr2 = arr;
		arr[1] = 4;
		std::cout << arr2[0] << std::endl;
		std::cout << arr2[1] << std::endl;
		std::cout << arr2[2] << std::endl;

		Array<float> arr3(arr);
		std::cout << arr3[0] << std::endl;
		std::cout << arr3[1] << std::endl;
		std::cout << arr3[2] << std::endl;
	}
	{
		std::cout << "\n    INT" << std::endl;
		Array<int> arr(3);
		Array<int> arr2(3);
		(void)arr;
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;
		std::cout << arr[0] << std::endl;
		std::cout << arr[1] << std::endl;
		std::cout << arr[2] << std::endl;
		arr2 = arr;
		arr[1] = 4;
		std::cout << arr2[0] << std::endl;
		std::cout << arr2[1] << std::endl;
		std::cout << arr2[2] << std::endl;

		Array<int> arr3(arr);
		std::cout << arr3[0] << std::endl;
		std::cout << arr3[1] << std::endl;
		std::cout << arr3[2] << std::endl;
	}
	std::cout << "\n    42 MAIN" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
