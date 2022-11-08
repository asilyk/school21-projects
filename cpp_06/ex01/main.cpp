/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:54:36 by fabet             #+#    #+#             */
/*   Updated: 2022/11/08 14:12:50 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error! Invalid number of arguments." << std::endl;
		return (1);
	}
	try
	{
		Conversion *conversion = new Conversion(argv[1]);
		std::cout << conversion;
		delete conversion;
	}
	catch(const Conversion::InvalidTypeException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
