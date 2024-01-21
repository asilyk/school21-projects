/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:51:20 by fabet             #+#    #+#             */
/*   Updated: 2022/10/26 18:07:02 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::Contact(
				size_t		index,
				std::string	firstName,
				std::string	lastName,
				std::string	nickName,
				std::string	phoneNumber,
				std::string	darkestSecret
				)
				: index(index)
				, firstName(firstName)
				, lastName(lastName)
				, nickName(nickName)
				, phoneNumber(phoneNumber)
				, darkestSecret(darkestSecret)
{
}
