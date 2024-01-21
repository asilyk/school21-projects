/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:14:07 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 07:14:08 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor was called." << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor was called." << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain destructor was called." << std::endl;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	if (this != &rhs)
		std::copy(rhs._ideas, rhs._ideas + 100, this->_ideas);
	return (*this);
}
