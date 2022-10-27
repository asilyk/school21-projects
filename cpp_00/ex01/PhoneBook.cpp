/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:20:41 by fabet             #+#    #+#             */
/*   Updated: 2022/10/27 14:16:58 by fabet            ###   ########.fr       */
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

static void	printHeader(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout
		<< "|" << std::setw(10) << "index"
		<< "|" << std::setw(10) << "first name"
		<< "|" << std::setw(10) << "last name"
		<< "|" << std::setw(10) << "nickname"
		<< "|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
}

static std::string	truncate(std::string const str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::search(void) const
{
	size_t	i = 0;
	size_t	index;

	printHeader();

	while (i < this->counter)
	{
		std::cout << "|" << std::setw(10) << this->contacts[i].index;
		std::cout
			<< "|" << std::setw(10) << truncate(this->contacts[i].firstName)
			<< "|" << std::setw(10) << truncate(this->contacts[i].lastName)
			<< "|" << std::setw(10) << truncate(this->contacts[i].nickName)
			<< "|" << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;
		i++;
	}
	std::cout << "Enter the index of the contact you are looking for: ";
	std::cin >> index;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (index >= this->counter || index < 0)
	{
		std::cout << "Error! Invalid index." << std::endl;
		return;
	}
	std::cout
			<< "First name: " << this->contacts[index].firstName << std::endl
			<< "Last name: " << this->contacts[index].lastName << std::endl
			<< "Nickname: " << this->contacts[index].nickName << std::endl
			<< "Phone number: " << this->contacts[index].phoneNumber << std::endl
			<< "Darkest secret: " << this->contacts[index].darkestSecret << std::endl
			<< std::endl;
}
