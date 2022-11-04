/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:14:37 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 07:14:38 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
public:
	Animal();
	Animal(const Animal &src);
	virtual ~Animal();

	Animal	&operator=(Animal const &rhs);

	virtual std::string	getType(void) const;

	virtual void	makeSound(void) const;
protected:
	std::string	_type;
};

#endif
