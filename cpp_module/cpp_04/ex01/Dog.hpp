/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:14:21 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 07:14:21 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
public:
	Dog();
	Dog(const Dog &src);
	virtual ~Dog();

	Dog	&operator=(Dog const &rhs);
	virtual void	makeSound(void) const;
private:
	Brain	*_brain;
};

#endif
