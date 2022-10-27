/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:59:27 by fabet             #+#    #+#             */
/*   Updated: 2022/10/27 12:34:23 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

static void	printStartInfo(void)
{
	std::cout
		<< "YOUR PHONEBOOK" << std::endl
		<< "The program only accepts ADD, SEARCH and EXIT." << std::endl
		<< "ADD: save a new contact." << std::endl
		<< "SEARCH: display a specific contact." << std::endl
		<< "EXIT: the program quits and the contacts are lost forever." << std::endl
		<< "Any other input is discarded." << std::endl
}

static void	getContactFields(std::string (&contactFields)[5])
{
	std::cout
		<< "Enter the contact fields one by one." << std::endl
		<< "The contact fields are: first name, last name, nickname, phone number, and darkest secret. "
		<< std::endl
		<< "A saved contact can’t have empty fields."
		<< std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "+";
		std::getline(std::cin, contactFields[i]);
		if (contactFields[i].empty())
		{
			std::cout << "Error! Contact field cannot be empty." << std::endl;
			i--;
		}
	}
}

int main()
{
	std::string	command;
	std::string	contactFields[5];
	PhoneBook	phonebook;

	printStartInfo();
	while (1)
	{
		std::cout << ">";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			getContactFields(contactFields);
			phonebook.addContact(
									contactFields[0],
									contactFields[1],
									contactFields[2],
									contactFields[3],
									contactFields[4]
									);
			continue;
		}
		if (command == "SEARCH")
		{
			phonebook.search();
			continue;
		}
		if (command == "EXIT")
		{
			std::cout << "The program quits and the contacts are lost forever." << std::endl;
			return (0);
		}
		std::cout << "Error! Unknown command." << std::endl;
		printStartInfo();
	}
}

// int main()
// {
// 	PhoneBook	phonebook;
//
// 	phonebook.addContact(
// 						"Oleg",
// 						"Tapov",
// 						"rocker",
// 						"212121",
// 						"dfghjkl jqiwjjqwiqw"
// 						);
// 	phonebook.addContact(
// 						"Alex",
// 						"Gapov",
// 						"goth",
// 						"128121",
// 						"sddsds dssd"
// 						);
// 	phonebook.addContact(
// 						"Gavrik",
// 						"Chepov",
// 						"puker",
// 						"12121233",
// 						"qwwqwq wqqwqw"
// 						);
// 	phonebook.addContact(
// 						"Papanya",
// 						"Thcal",
// 						"krolikkorolkrol",
// 						"121498329283323893212",
// 						"dsdssd ds"
// 						);
// 	phonebook.addContact(
// 						"Happypoklonskiy",
// 						"Iron",
// 						"man",
// 						"1455454",
// 						"assasa"
// 						);
// 	phonebook.addContact(
// 						"Wise",
// 						"Tree",
// 						"tree",
// 						"121908",
// 						"fgfdffddf"
// 						);
// 	phonebook.addContact(
// 						"Gavrik",
// 						"Chickov",
// 						"chicka",
// 						"466954854",
// 						"qwwqwq wqqwqw"
// 						);
// 	phonebook.addContact(
// 						"Hasbikalotuan",
// 						"Abdurozev",
// 						"hasbik",
// 						"123323",
// 						"sdssdd"
// 						);

// 	phonebook.search();
// }
