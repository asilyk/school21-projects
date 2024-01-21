/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:10:43 by fabet             #+#    #+#             */
/*   Updated: 2022/10/30 04:51:00 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB(void);
	void	attack() const;
	void	setWeapon(Weapon &weapon);

private:
	std::string	_name;
	Weapon		*_weapon;
};

#endif
