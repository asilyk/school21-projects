/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:46:46 by fabet             #+#    #+#             */
/*   Updated: 2022/10/31 11:39:57 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::_numberOfFractionalBits = 8;

Fixed::Fixed() : _fixedPointNumber(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int number)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNumber = number << this->_numberOfFractionalBits;
}

Fixed::Fixed(const float number)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNumber = roundf(number * (1 << this->_numberOfFractionalBits));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointNumber = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

float	Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++()
{
	this->_fixedPointNumber++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->_fixedPointNumber--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->_fixedPointNumber;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->_fixedPointNumber;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs.toFloat() <= rhs.toFloat())
		return (lhs);
	else
		return (rhs);
}

const Fixed	&Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs.toFloat() <= rhs.toFloat())
		return (lhs);
	else
		return (rhs);
}

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs.toFloat() >= rhs.toFloat())
		return (lhs);
	else
		return (rhs);
}

const Fixed	&Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs.toFloat() >= rhs.toFloat())
		return (lhs);
	else
		return (rhs);
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointNumber);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointNumber = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointNumber / (float)(1 << this->_numberOfFractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedPointNumber >> this->_numberOfFractionalBits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}