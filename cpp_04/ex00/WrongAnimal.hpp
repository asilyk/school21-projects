/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:14:55 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 07:14:56 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	~WrongAnimal();

	WrongAnimal	&operator=(WrongAnimal const &rhs);

	std::string	getType(void) const;

	void	makeSound(void) const;
protected:
	std::string	_type;
};
#endif
