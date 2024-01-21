/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:51:23 by fabet             #+#    #+#             */
/*   Updated: 2022/10/26 21:59:47 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
public:
	size_t		index;
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	Contact(void);

	Contact(
			size_t		index,
			std::string	firstName,
			std::string	lastName,
			std::string	nickName,
			std::string	phoneNumber,
			std::string	darkestSecret
			);
};

#endif
