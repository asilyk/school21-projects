/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:14:15 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 07:14:16 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
public:
	Cat();
	Cat(const Cat &src);
	virtual ~Cat();

	Cat	&operator=(Cat const &rhs);
	virtual void	makeSound(void) const;
private:
	Brain	*_brain;
};

#endif
