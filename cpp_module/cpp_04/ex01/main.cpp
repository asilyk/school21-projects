/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:14:23 by fabet             #+#    #+#             */
/*   Updated: 2022/11/05 10:05:25 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal	*animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << animals[i]->getType()<< std::endl;
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; i++)
		delete animals[i];

	Cat	*cat1 = new Cat();
	Cat	*cat2 = new Cat(*cat1);

	delete cat1;
	delete cat2;

	return (0);
}
