#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _health(10), _energy(10), _damage(0)
{
	std::cout
			<< "Default ClapTrap is created!"
			<< std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _damage(0)
{
	std::cout
			<< "ClapTrap " << this->_name
			<< " is created!"
			<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout
			<< "ClapTrap " << this->_name
			<< " is destroyed!"
			<< std::endl;
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

bool	ClapTrap::isAlive() const
{
	bool	isAlive = this->_health > 1;

	if (!isAlive)
		std::cout
				<< "ClapTrap " << this->_name
				<< " is dead!"
				<< std::endl;
	return (isAlive);
}

bool	ClapTrap::hasEnergy() const
{
	bool	hasEnergy = this->_energy > 1;

	if (!hasEnergy)
		std::cout
				<< "ClapTrap " << this->_name
				<< " does not have energy points!"
				<< std::endl;
	return (hasEnergy);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!(this->isAlive() && this->hasEnergy()))
		return;
	this->_energy--;
	std::cout
		<< "ClapTrap " << this->_name
		<< " attacks " << target << ", causing "
		<< this->_damage << " points of damage!"
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_health -= amount;
	std::cout
		<< "ClapTrap " << this->_name
		<< " is attacked, loses " << amount
		<< " health points and now has " << this->_health
		<< " health points."
		<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!(this->isAlive() && this->hasEnergy()))
		return;
	this->_health += amount;
	this->_energy--;
	std::cout
		<< "ClapTrap " << this->_name
		<< " repairs itself for " << amount
		<< " health points and now has " << this->_health
		<< " health points."
		<< std::endl;
}