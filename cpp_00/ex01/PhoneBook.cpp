/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:20:41 by fabet             #+#    #+#             */
/*   Updated: 2022/10/26 19:09:06 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->counter = 0;
}

void	PhoneBook::addContact(
							std::string	firstName,
							std::string	lastName,
							std::string	nickName,
							std::string	phoneNumber,
							std::string	darkestSecret
							)
{
	static int	i = 0;

	if (i > 7)
		i = 0;
	else
		this->counter++;
	this->contacts[i] = Contact(
								i,
								firstName,
								lastName,
								nickName,
								phoneNumber,
								darkestSecret
								);
	i++;
}

void	PhoneBook::search(void)
{
	size_t	i = 0;

	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout
		<< "|" << std::setw(10) << "index"
		<< "|" << std::setw(10) << "first name"
		<< "|" << std::setw(10) << "last name"
		<< "|" << std::setw(10) << "nickname"
		<< "|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;

	while (i < this->counter)
	{
		std::cout << "|" << std::setw(10) << this->contacts[i].index;
		std::cout
		<< "|" << std::setw(10) << this->contacts[i].firstName.resize(10)
		<< "|" << std::setw(10) << this->contacts[i].lastName.resize(10)
		<< "|" << std::setw(10) << this->contacts[i].nickName.resize(10)
		<< "|" << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;
		i++;
	}
}
