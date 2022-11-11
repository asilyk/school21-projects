/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:11:52 by fabet             #+#    #+#             */
/*   Updated: 2022/11/11 14:41:19 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _maxSize(0)
{
}

Span::Span(unsigned int N): _maxSize(N)
{
	// std::cout << "Span of size " << N << " is created!" << std::endl;
	this->_storage.reserve(this->getMaxSize());
}

Span::Span(const Span &src): _maxSize(src.getMaxSize())
{
	// std::cout << "Span is created with copy constructor!" << std::endl;
	*this = src;
}

Span::~Span()
{
	// std::cout << "Span is destroyed!" << std::endl;
}

Span	&Span::operator=(const Span &src)
{
	if (this == &src)
		return *this;

	this->_storage = src.getStorage();
	this->_maxSize = src.getMaxSize();

	return *this;
}

void	Span::addNumber(int number)
{
	if (this->getMaxSize() < 1)
		throw (Span::VectorInvalidException());
	if (this->_storage.size() + 1 > this->getMaxSize())
		throw (Span::ArrayFullException());

	this->_storage.push_back(number);
}

void	Span::addNumbers(unsigned int amount)
{
	srand(time(NULL));

	for (unsigned int i = 0; i < amount; i++)
		addNumber(rand());
}

int	Span::shortestSpan() const
{
	if (this->_storage.size() == 1)
		throw (Span::ComparisonInvalidException());

	std::vector<int>	temp(this->_storage);

	std::sort(temp.begin(), temp.end());

	int	shortestSpan = INT_MAX;
	std::vector<int>::iterator it = temp.begin();
	std::vector<int>::iterator itn = temp.begin() + 1;

	while (itn != temp.end())
	{
		if ((*itn - *it) < shortestSpan)
			shortestSpan = *itn - *it;
		++itn;
		++it;
	}

	return (shortestSpan);
}

int	Span::longestSpan() const
{
	if (this->_storage.size() == 1)
		throw (Span::ComparisonInvalidException());

	std::vector<int>	temp(this->_storage);

	std::sort(temp.begin(), temp.end());

	return (*(temp.end() - 1) - *temp.begin());
}

unsigned int	Span::getMaxSize() const
{
	return (this->_maxSize);
}

std::vector<int>	Span::getStorage() const
{
	return (this->_storage);
}

const char	*Span::VectorInvalidException::what() const throw()
{
	return ("Error: Invalid or broken vector");
}

const char	*Span::ArrayFullException::what() const throw()
{
	return ("Error: Array full");
}

const char	*Span::ComparisonInvalidException::what() const throw()
{
	return ("Error: more than one element in vector needed to be compared");
}
