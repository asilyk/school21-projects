/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:38:52 by fabet             #+#    #+#             */
/*   Updated: 2022/11/11 18:04:58 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>()
	{
		// std::cout << "MutantStack is created!" << std::endl;
	}

	MutantStack(const std::stack<T> &src) : std::stack<T>(src)
	{
		// std::cout << "MutantStack is created with copy constructor!" << std::endl;
	}

	~MutantStack()
	{
		// std::cout << "MutantStack is destroyed!" << std::endl;
	}

	std::stack<T>	&operator=(const std::stack<T> &src)
	{
		if (*this != src)
			*this = src;
		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator	iterator;

	iterator	begin()
	{
		return (std::stack<T>::c.begin());
	}

	iterator	end()
	{
		return (std::stack<T>::c.end());
	}
};

#endif
