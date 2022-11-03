#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap();

	ClapTrap	&operator=(ClapTrap const &rhs);

//	std::string	getName(void) const;
//	int 		getHealth(void) const;
//	int 		getEnergy(void) const;
//	int 		getDamage(void) const;

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
private:
	std::string	_name;
	int			_health = 10;
	int 		_energy = 10;
	int 		_damage = 0;
};


#endif
