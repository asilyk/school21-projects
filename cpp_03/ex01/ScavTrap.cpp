/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:42:12 by fabet             #+#    #+#             */
/*   Updated: 2022/11/03 16:42:13 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->_name = "Default";
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	this->_isGuardGate = false;
	std::cout
			<< "Default ScavTrap is created!"
			<< std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	this->_isGuardGate = false;
	std::cout
			<< "ScavTrap " << this->_name
			<< " is created!"
			<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout
			<< "ScavTrap " << this->_name
			<< " is destroyed!"
			<< std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_health = rhs._health;
		this->_energy = rhs._energy;
		this->_damage = rhs._damage;
		this->_isGuardGate = rhs._isGuardGate;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (!(this->isAlive() && this->hasEnergy()))
		return;
	this->_energy--;
	std::cout
			<< "ScavTrap " << this->_name
			<< " attacks " << target << ", causing "
			<< this->_damage << " points of damage!"
			<< std::endl;
}

void	ScavTrap::guardGate()
{
	if (!this->isAlive())
		return;
	std::cout << "ScavTrap " << this->_name;
	if (_isGuardGate)
	{
		_isGuardGate = false;
		std::cout << "is not now in guard mode."<< std::endl;
	}
	else
	{
		_isGuardGate = true;
		std::cout << "is now in guard mode."<< std::endl;
	}
}
