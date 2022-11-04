/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:14:12 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 07:14:13 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat default constructor was called." << std::endl;
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor was called." << std::endl;
	*this = src;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor was called." << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = rhs._brain;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat meows." << std::endl;
}
