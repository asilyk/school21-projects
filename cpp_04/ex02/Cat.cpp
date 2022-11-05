/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:11:30 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 18:44:37 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): AAnimal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat default constructor was called." << std::endl;
}

Cat::Cat(const Cat &src): AAnimal()
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
