/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:41:58 by fabet             #+#    #+#             */
/*   Updated: 2022/11/03 16:41:59 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	trap("Jack");

	for (int i = 0; i < 9; i++)
	{
		trap.attack("Ben");
		trap.takeDamage(2);
		trap.beRepaired(2);
	}
	return (0);
}
