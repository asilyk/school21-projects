/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:14:58 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 18:43:48 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor was called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal()
{
	std::cout << "WrongCat copy constructor was called." << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor was called." << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat meows." << std::endl;
}
