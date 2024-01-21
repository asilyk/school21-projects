/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:14:40 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 18:43:05 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor was called." << std::endl;
}

Cat::Cat(const Cat &src): Animal()
{
	std::cout << "Cat copy constructor was called." << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat destructor was called." << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat meows." << std::endl;
}
