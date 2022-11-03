#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default")
{
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
}

ClapTrap::~ClapTrap()
{
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_health = rhs._health;
		this->_energy = rhs._energy;
		this->_damage = rhs._damage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energy < 1)
	{
		std::cout
			<< "ClapTrap " << this->_name
			<< "does not have energy points!"
			<< std::endl;
		return;
	}
	std::cout
		<< "ClapTrap " << this->_name
		<< " attacks " << target << " , causing "
		<< this->_damage << " points of damage!"
		<< std::endl;
	this->_energy--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy < 1)
	{
		std::cout
				<< "ClapTrap " << this->_name
				<< "does not have energy points!"
				<< std::endl;
		return;
	}
	std::cout
		<< "ClapTrap " << this->_name
		<< " repairs itself for " << amount
		<< " health points."
		<< std::endl;
	this->_health += amount;
	this->_energy--;
}