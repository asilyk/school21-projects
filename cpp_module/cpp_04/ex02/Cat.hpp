/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:11:32 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 07:11:53 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
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
