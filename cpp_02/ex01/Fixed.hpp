/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:46:51 by fabet             #+#    #+#             */
/*   Updated: 2022/10/31 10:41:32 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const &src);
	Fixed(const int);
	Fixed(const float);

	~Fixed();

	Fixed	&operator=(Fixed const &rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					_fixedPointNumber;
	static int const	_numberOfFractionalBits = 8;
};

#endif
