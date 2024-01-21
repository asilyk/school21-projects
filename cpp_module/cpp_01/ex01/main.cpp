/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:55:32 by fabet             #+#    #+#             */
/*   Updated: 2022/10/29 16:42:21 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie*	horde = zombieHorde(4, "Steven");

	for (int i = 0; i < 4; i++)
	{
		std:: cout << "Zombie Horde [" << i << "]: ";
		horde[i].announce();
	}

	delete [] horde;

	return 0;
}
