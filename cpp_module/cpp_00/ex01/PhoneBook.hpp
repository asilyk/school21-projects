/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:10:58 by fabet             #+#    #+#             */
/*   Updated: 2022/10/27 20:34:13 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	size_t	_counter;

public:
	PhoneBook(void);

	void	addContact(
						std::string	firstName,
						std::string	lastName,
						std::string	nickName,
						std::string	phoneNumber,
						std::string	darkestSecret
						);

	void	search(void) const;
};

#endif
