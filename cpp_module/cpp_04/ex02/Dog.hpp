/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:11:37 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 07:11:55 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
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
