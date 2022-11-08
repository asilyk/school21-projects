/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:38:32 by fabet             #+#    #+#             */
/*   Updated: 2022/11/08 18:50:43 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <string>
#include <iostream>

class Data
{
public:
	Data();
	Data(const std::string data);
	Data(const Data &src);
	~Data();

	Data &operator=(const Data &rhs);

	std::string	getData() const;
private:
	std::string	_data;
};

uintptr_t serialize(Data *ptr);

Data* deserialize(uintptr_t raw);

#endif
