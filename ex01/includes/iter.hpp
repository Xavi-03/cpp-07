#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>

#define MAX_VAL 10

template <typename T>
void	iter(T *array, int length, void (*f)(T&)) {
	for (int i = 0; i < length; i++) {
		f(array[i]);
	}
}

template <typename T>
void	print(T &value) {
	std::cout << value << std::endl;
}

template <typename T>
void	add(T &a) {
	T b = 5;
	a += b;
}

#endif
