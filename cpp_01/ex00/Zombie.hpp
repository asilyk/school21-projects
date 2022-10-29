/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:38:12 by fabet             #+#    #+#             */
/*   Updated: 2022/10/29 15:56:41 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

class Zombie
{
public:
	Zombie(std::string name);
	~Zombie();
	void	announce(void);

private:
	std::string	_name;
};

Zombie*	newZombie(std::string name);

void randomChump(std::string name);
