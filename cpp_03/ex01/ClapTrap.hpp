/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:42:06 by fabet             #+#    #+#             */
/*   Updated: 2022/11/03 16:42:06 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

protected:
	std::string	_name;
	int			_health;
	int 		_energy;
	int 		_damage;

	bool	isAlive() const;
	bool	hasEnergy() const;
};


#endif
