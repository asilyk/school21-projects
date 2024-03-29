/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:45:52 by fabet             #+#    #+#             */
/*   Updated: 2022/10/29 16:35:01 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Nameless zombie " << " is alive." << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie " << this->_name << " is alive." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " is dead." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	std::cout << "Zombie named " << name << "." << std::endl;
}
