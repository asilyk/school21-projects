#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->_name = "Default";
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout
			<< "Default FragTrap is created!"
			<< std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout
			<< "FragTrap " << this->_name
			<< " is created!"
			<< std::endl;
}

FragTrap::FragTrap(FragTrap const &src)
{
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout
			<< "FragTrap " << this->_name
			<< " is destroyed!"
			<< std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (!(this->isAlive() && this->hasEnergy()))
		return;
	this->_energy--;
	std::cout
			<< "FragTrap " << this->_name
			<< " attacks " << target << ", causing "
			<< this->_damage << " points of damage!"
			<< std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (!this->isAlive())
		return;
	std::cout << "FragTrap " << this->_name << ": high fives guys!" << std::endl;
}
