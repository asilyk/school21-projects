/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:11:13 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 07:11:14 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal default constructor was called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal copy constructor was called." << std::endl;
	*this = src;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor was called." << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

