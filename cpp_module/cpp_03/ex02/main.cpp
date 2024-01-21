/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:42:34 by fabet             #+#    #+#             */
/*   Updated: 2022/11/03 16:42:40 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	trap("Jack");

	for (int i = 0; i < 5; i++)
	{
		trap.attack("Ben");
		trap.takeDamage(10);
		trap.beRepaired(5);
	}
	trap.highFivesGuys();
	return (0);
}
