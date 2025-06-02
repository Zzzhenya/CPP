/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:57:33 by sde-silv          #+#    #+#             */
/*   Updated: 2025/05/27 20:51:56 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T> 
Array<T>::Array(void):  _n(0)
{
	_arr = new T[0];
	std::cout << "default arr constructor\n";
}

template <typename T>
T	*reset(T	*arr, unsigned int n)
{
	try
	{
		for (unsigned int i = 0; i < n; i++)
			arr[i] = static_cast<T>( 0 );
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		std::cout << "trying std::string" << std::endl;
		// for (unsigned int i = 0; i < n; i++)
		// 	_arr[i] = static_cast<T>(std::string(""));

	}
	return (arr);
}

template <typename T> 
Array<T>::Array(const unsigned int n): _n(n)
{
	_arr = new T[n];
	_arr = reset<T>(_arr, _n);
	std::cout << "n len = " << n << " arr constructor\n";
}

template <typename T> 
Array<T>::~Array(void)
{
	//if (_arr != NULL)
	delete [] _arr;
	_n = 0;
	std::cout << "arr destructor\n";
}

template <typename T>
Array<T>::Array(const Array &other)
{
	//if (this->_n > 0 || this->_arr != NULL)
	//	delete [] this->_arr;
	this->_n = other._n;
	this->_arr = new T[other._n];
	_arr = reset<T>(_arr, _n);
	for (unsigned int i = 0; i < other._n; i++)
		this->setVal(i, other._arr[i]);

	std::cout << "copy arr constructor\n";
}

template <typename T>
T 	&Array<T>::getVal(unsigned int loc) const
{
	return (this->_arr[loc]);
}

template <typename T>
void 	Array<T>::setVal(unsigned int loc, T &val) const
{
	this->_arr[loc] = val;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this->_n > 0)
		delete [] this->_arr;

	this->_n = other._n;
	this->_arr = new T[other._n];
	_arr = reset<T>(_arr, _n);
	for (unsigned int i = 0; i < other._n; i++)
		this->setVal(i, other._arr[i]);

	std::cout << "copy assignment operator overload\n";

	return (*this);
}

template <typename T>
T  	&Array<T>::operator[](unsigned int i) const
{
	if (i >= _n || i < 0)
		throw std::out_of_range("exception: index out of range");
	return (getVal(i));
}

template <typename T>
const unsigned int &Array<T>::size(void) const
{
	return(this->_n);
}

#endif
