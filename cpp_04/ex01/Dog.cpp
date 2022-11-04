/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:14:18 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 07:14:18 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor was called." << std::endl;
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor was called." << std::endl;
	*this = src;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor was called." << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = rhs._brain;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog barks." << std::endl;
}
