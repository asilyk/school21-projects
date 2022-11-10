/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:32:29 by fabet             #+#    #+#             */
/*   Updated: 2022/11/09 20:03:51 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	addFive(T &element)
{
	element += 5;
}

template<typename T>
void	iter(T *array, int len, void (*func)(T &))
{
	if (array == NULL || func == NULL || len < 1)
		return ;
	for (int i = 0; i < len; i++)
		func(array[i]);
}

#endif
