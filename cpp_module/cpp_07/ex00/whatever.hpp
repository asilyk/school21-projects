/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:57:29 by fabet             #+#    #+#             */
/*   Updated: 2022/11/10 14:58:05 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &lhs, T &rhs)
{
	T temp = lhs;
	lhs = rhs;
	rhs = temp;
}

template<typename T>
T	const &min(const T &lhs, const T &rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

template<typename T>
T	const &max(const T &lhs, const T &rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

#endif
