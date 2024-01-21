/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:43:04 by fabet             #+#    #+#             */
/*   Updated: 2022/11/08 18:59:55 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): _data("data")
{
	std::cout << "Default Data is created!" << std::endl;
}

Data::Data(const std::string data): _data(data)
{
	std::cout << "Data is created!" << std::endl;
}

Data::Data(const Data &src): _data(src.getData())
{
	std::cout << "Data is created with copy constructor!" << std::endl;
	*this = src;
}

Data::~Data()
{
	std::cout << "Data is destroyed!" << std::endl;
}

Data	&Data::operator=(const Data &rhs)
{
	if (this == &rhs)
		return *this;

	this->_data = rhs.getData();
	return *this;
}

std::string	Data::getData() const
{
	return (this->_data);
}

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
