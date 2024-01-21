/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:37:35 by fabet             #+#    #+#             */
/*   Updated: 2022/11/08 19:01:34 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	main()
{
	Data *data = new Data("Hello");
	std::cout << "Data *data: " << data << ", " << data->getData() << std::endl;
	uintptr_t ptr = serialize(data);
	std::cout << "uintptr_t ptr: " << ptr << std::endl;
	Data *newData = deserialize(ptr);
	std::cout << "Data *newData: " << newData << ", " << newData->getData() << std::endl;
	delete data;
	return (0);
}
