/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:59:27 by fabet             #+#    #+#             */
/*   Updated: 2022/10/26 19:07:33 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	phonebook.addContact(
						"Oleg",
						"Tapov",
						"rocker",
						"212121",
						"dfghjkl jqiwjjqwiqw"
						);
	phonebook.addContact(
						"Alex",
						"Gapov",
						"goth",
						"128121",
						"sddsds dssd"
						);
	phonebook.addContact(
						"Gavrik",
						"Chepov",
						"puker",
						"12121233",
						"qwwqwq wqqwqw"
						);
	phonebook.addContact(
						"Papanya",
						"Thcal",
						"krol",
						"121498329283323893212",
						"dsdssd ds"
						);
	phonebook.addContact(
						"Happypoklonskiy",
						"Iron",
						"man",
						"1455454",
						"assasa"
						);
	phonebook.addContact(
						"Wise",
						"Tree",
						"tree",
						"121908",
						"fgfdffddf"
						);
	phonebook.addContact(
						"Gavrik",
						"Chickov",
						"chicka",
						"466954854",
						"qwwqwq wqqwqw"
						);
	phonebook.addContact(
						"Hasbikalotuan",
						"Abdurozev",
						"hasbik",
						"123323",
						"sdssdd"
						);

	phonebook.search();
}
