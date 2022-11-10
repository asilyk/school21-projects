/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:32:32 by fabet             #+#    #+#             */
/*   Updated: 2022/11/10 08:26:53 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int	main()
{
	int	array[] = {4, 5, 8, 11};
	iter(&array, 4, addFive<int>);
	for (int i = 0; i < 4; i++)
		std::cout << array[i] << std::endl;
	return (0);
}
