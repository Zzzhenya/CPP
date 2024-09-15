#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "Array.tpp"
# include <iostream>

template <typename T> 
class Array
{
	public:
		Array(void);
		~Array(void);
		Array(const unsigned int n);
		Array(const Array &other);
		Array 				&operator=(const Array &other);

		T 					*_arr;
		unsigned int		_n;
};


template <typename T> 
Array<T>::Array(void): _arr(NULL), _n(0)
{
	std::cout << "default arr constructor\n";
}

template <typename T> 
Array<T>::Array(const unsigned int n):_arr(new T[n]), _n(n)
{
	std::cout << "n len = " << n << " arr constructor\n";
}

template <typename T> 
Array<T>::~Array(void)
{
	if (_arr != NULL)
		delete [] _arr;
	std::cout << "arr destructor\n";
}

template <typename T>
Array<T>::Array(const Array &other)
{
	if (this->_n > 0 || this->_arr != NULL)
		delete [] this->_arr;

	this->_n = other._n;
	this->_arr = new T[other._n];
	for (unsigned int i = 0; i < other._n; i++)
		this->_arr[i] = other._arr[i];

	std::cout << "copy arr constructor\n";
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this->_n > 0)
		delete [] this->_arr;

	this->_n = other._n;
	this->_arr = new T[other._n];
	for (unsigned int i = 0; i < other._n; i++)
		this->_arr[i] = other._arr[i];

	std::cout << "copy assignment operator overload\n";

	return (*this);
}

#endif
