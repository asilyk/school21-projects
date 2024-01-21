/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:10:20 by fabet             #+#    #+#             */
/*   Updated: 2022/11/08 19:35:07 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	// std::cout << "Base is destroyed!" << std::endl;
}

Base	*generate()
{
	int	randomInt = rand() % 3;

	if (randomInt == 0)
		return (new A());
	else if (randomInt == 1)
		return (new B());
	return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A is the identified type." << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B is the identified type." << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C is the identified type." << std::endl;
	else
		std::cout << "Unknown type." << std::endl;
}

void	identify(Base &p)
{
	try
	{
		Base &base =dynamic_cast<A &>(p);
		std::cout << "A is the identified type." << std::endl;
		(void)base;
		return;
	}
	catch(std::bad_cast &bc)
	{
	}
	try
	{
		Base &base =dynamic_cast<B &>(p);
		std::cout << "B is the identified type." << std::endl;
		(void)base;
		return;
	}
	catch(std::bad_cast &bc)
	{
	}
	try
	{
		Base &base =dynamic_cast<C &>(p);
		std::cout << "C is the identified type." << std::endl;
		(void)base;
		return;
	}
	catch(std::bad_cast &bc)
	{
	}
	std::cout << "Unknown type." << std::endl;
}
