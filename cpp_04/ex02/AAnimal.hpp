/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:11:20 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 07:17:13 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
public:
	AAnimal();
	AAnimal(const AAnimal &src);
	virtual ~AAnimal();

	AAnimal	&operator=(AAnimal const &rhs);

	virtual std::string	getType(void) const;

	virtual void	makeSound(void) const = 0;
protected:
	std::string	_type;
};

#endif
