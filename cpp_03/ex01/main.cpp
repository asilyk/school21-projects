/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:42:08 by fabet             #+#    #+#             */
/*   Updated: 2022/11/03 16:42:09 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	trap("Jack");

	for (int i = 0; i < 5; i++)
	{
		trap.attack("Ben");
		trap.takeDamage(10);
		trap.beRepaired(5);
	}
	trap.guardGate();
	trap.guardGate();
	trap.guardGate();
	return (0);
}
