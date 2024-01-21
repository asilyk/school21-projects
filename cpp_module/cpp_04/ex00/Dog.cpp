/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:14:45 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 18:43:10 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor was called." << std::endl;
}

Dog::Dog(const Dog &src): Animal()
{
	std::cout << "Dog copy constructor was called." << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog destructor was called." << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog barks." << std::endl;
}
