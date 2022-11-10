/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:21:12 by fabet             #+#    #+#             */
/*   Updated: 2022/11/09 19:58:17 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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

int	main()
{
	int	a = 2;
	int	b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}
