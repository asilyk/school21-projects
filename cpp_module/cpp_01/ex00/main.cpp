/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:55:32 by fabet             #+#    #+#             */
/*   Updated: 2022/10/29 16:15:29 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	jack = Zombie("Jack");
	jack.announce();

	Zombie	*donny = new Zombie("Donny");
	donny->announce();
	delete donny;

	randomChump("Billie");

	Zombie	*jerry = newZombie("Jerry");
	jerry->announce();
	delete jerry;

	return 0;
}
