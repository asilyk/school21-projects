/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:03:16 by fabet             #+#    #+#             */
/*   Updated: 2022/10/29 18:51:57 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
public:
	Weapon(std::string type);
	~Weapon(void);
	std::string const	&getType(void) const;
	void				setType(std::string const newType);
private:
	std::string	_type;
};

#endif
