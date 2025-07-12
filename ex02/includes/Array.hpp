#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# include <exception>

template <class T>
class Array {
private:
	T				*_arr;
	unsigned int	_size;
public:
//  ORTHODOXAL CANONICAL FORM  //
	Array(void);
	Array(const Array &src);
	const Array &operator = (const Array &src);
	~Array(void);

//  SPECIFIC CONSTRUCTOR  //
	Array(unsigned int n);

//  SPECIFIC OPERATOR  //
	T &operator [] (unsigned int i);

//  EXCEPTIONS  //
	class OverFlowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

//  ORTHODOXAL CANONICAL FORM  //
template <class T>
Array<T>::Array(void) {
	std::cout << "Array constructor" << std::endl;
	_arr = NULL;
	_size = 0;
}

template <class T>
Array<T>::Array(const Array &src) {
	std::cout << "Array copy constructor" << std::endl;
	_arr = NULL;
	_size = 0;
	*this = src;
}

template <class T>
const Array<T> &Array<T>::operator = (const Array &src) {
	std::cout << "Array assigment operator" << std::endl;
	if (_arr)
		delete []_arr;
	_arr = new T[src._size];
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = src._arr[i];
	return *this;
}

template <class T>
Array<T>::~Array(void) {
	std::cout << "Array destructor" << std::endl;
	if (_arr)
		delete []_arr;
}

//  SPECIFIC CONSTRUCTOR  //
template <class T>
Array<T>::Array(unsigned int n) {
	std::cout << "Array Specific constructor" << std::endl;
	_arr = new T[n];
	_size = n;
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = 0;
}

//  SPECIFIC OPERATOR  //
template <class T>
T &Array<T>::operator [] (unsigned int i) {
	if (i < _size)
		return _arr[i];
	throw OverFlowException();
	return _arr[0];
}

//  EXCEPTIONS  //
template <typename T>
const char *Array<T>::OverFlowException::what(void) const throw(){
	const char *error =  "Error: Arrey is not accesible";
	return error;
}


#endif
