/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:32:29 by fabet             #+#    #+#             */
/*   Updated: 2022/11/10 16:06:29 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	print(T const &element)
{
	std::cout << element << std::endl;
}

template<typename T>
void	iter(T *array, int len, void (*func)(T const &))
{
	if (array == NULL || func == NULL || len < 1)
		return ;
	for (int i = 0; i < len; i++)
		func(array[i]);
}

#endif
