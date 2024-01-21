/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:17:49 by fabet             #+#    #+#             */
/*   Updated: 2022/11/10 16:41:42 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array(): _size(0)
{
	this->_array = new T[this->_size];
}

template<typename T>
Array<T>::Array(int size): _size(size)
{
	this->_array = new T[this->_size];
}

template<typename T>
Array<T>::Array(const Array &src): _size(src.getSize())
{
	this->_array = NULL;
	*this = src;
}

template<typename T>
Array<T>::~Array()
{
	if (this->_array != NULL)
		delete [] this->_array;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array<T> &src)
{
	if (this->_array != NULL)
		delete [] this->_array;
	if (src.getSize() != 0)
	{
		this->_size = src.getSize();
		this->_array = new T[this->_size];
		for (int i = 0; i < this->getSize(); i++)
			this->_array[i] = src._array[i];
	}
	return (*this);
}

template<typename T>
T&	Array<T>::operator[](int index) const
{
	if (index > this->_size - 1)
		throw(InvalidIndexException());

	return (this->_array[index]);
}

template<typename T>
int	Array<T>::getSize() const
{
	return (this->_size);
}

template<typename T>
const char	*Array<T>::InvalidIndexException::what() const throw()
{
	return ("Error: Index of element is out of range of Array");
}

#endif
