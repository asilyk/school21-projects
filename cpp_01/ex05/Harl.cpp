/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:46:02 by fabet             #+#    #+#             */
/*   Updated: 2022/10/30 07:43:10 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. "
		<< "I really do!"
		<< std::endl;
}

void	Harl::info(void)
{
	std::cout
		<< "I cannot believe adding extra bacon costs more money. "
		<< "You didnt put enough bacon in my burger! "
		<< "If you did, I wouldnt be asking for more!"
		<< std::endl;
}

void	Harl::warning(void)
{
	std::cout
		<< "I think I deserve to have some extra bacon for free. "
		<< "Ive been coming for years whereas you started working here since last month."
		<< std::endl;
}

void	Harl::error(void)
{
	std::cout
		<< "This is unacceptable! "
		<< "I want to speak to the manager now."
		<< std::endl;
}

void	Harl::complain(std::string level)
{
	std::string names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
		if (names[i] == level)
			(this->*functions[i])();
}
