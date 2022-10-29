/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:13:18 by fabet             #+#    #+#             */
/*   Updated: 2022/10/29 19:04:46 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
	this->_name = name;
	this->_weapon = &weapon;
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack() const
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
