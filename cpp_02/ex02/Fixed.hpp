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
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const &src);
	Fixed(const int number);
	Fixed(const float number);

	~Fixed();

	Fixed	&operator=(Fixed const &rhs);
	bool	operator>(Fixed fixed) const;
	bool	operator<(Fixed fixed) const;
	bool	operator>=(Fixed fixed) const;
	bool	operator<=(Fixed fixed) const;
	bool	operator==(Fixed fixed) const;
	bool	operator!=(Fixed fixed) const;
	float	operator+(Fixed fixed) const;
	float	operator-(Fixed fixed) const;
	float	operator*(Fixed fixed) const;
	float	operator/(Fixed fixed) const;
	Fixed	operator++();
	Fixed	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed &min(Fixed &lhs, Fixed &rhs);
	static const Fixed &min(Fixed const &lhs, Fixed const &rhs);
	static Fixed &max(Fixed &lhs, Fixed &rhs);
	static const Fixed &max(Fixed const &lhs, const Fixed &rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					_fixedPointNumber;
	static int const	_numberOfFractionalBits;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif
