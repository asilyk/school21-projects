/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:11:54 by fabet             #+#    #+#             */
/*   Updated: 2022/11/11 14:40:12 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
public:
	Span();
	Span(unsigned int N);
	Span(const Span &src);
	~Span();

	Span	&operator=(const Span &src);

	void	addNumber(int number);
	void	addNumbers(unsigned int amount);

	int	shortestSpan() const;
	int	longestSpan() const;

	unsigned int		getMaxSize() const;
	std::vector<int>	getStorage() const;

	class VectorInvalidException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class ArrayFullException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class ComparisonInvalidException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

private:
	std::vector<int>	_storage;
	unsigned int		_maxSize;
};

#endif
