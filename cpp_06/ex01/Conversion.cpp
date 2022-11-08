/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:01:21 by fabet             #+#    #+#             */
/*   Updated: 2022/11/08 14:15:29 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(): _input("0")
{
	// std::cout << "Default Conversion is created!" << std::endl;
}

Conversion::Conversion(const std::string input): _input(input)
{
	// std::cout << "Conversion for " << this->getInput() << " is created!" << std::endl;
	this->_double = atof(this->getInput().c_str());
	this->convertInput();
}

Conversion::Conversion(const Conversion &src): _input(src.getInput())
{
	// std::cout << "Conversion is destroyed!" << std::endl;
	*this = src;
}

Conversion::~Conversion()
{
	// std::cout << "Conversion Deconstructor called" << std::endl;
}

Conversion	&Conversion::operator=(const Conversion &rhs)
{
	if (this == &rhs)
		return *this;

	this->_type = rhs.getType();
	this->_char = rhs.getChar();
	this->_int = rhs.getInt();
	this->_float = rhs.getFloat();
	this->_double = rhs.getDouble();
	return *this;
}

std::string	Conversion::getInput() const
{
	return (this->_input);
}

int	Conversion::getType() const
{
	return (this->_type);
}

char	Conversion::getChar() const
{
	return (this->_char);
}

int	Conversion::getInt() const
{
	return (this->_int);
}

float	Conversion::getFloat() const
{
	return (this->_float);
}

double Conversion::getDouble() const
{
	return (this->_double);
}

const char	*Conversion::InvalidTypeException::what() const throw()
{
	return ("Error! Impossible to print or input is not convertable.");
}

type	Conversion::findType()
{
	if (this->getInput().compare("nan") == 0 || this->getInput().compare("+inf") == 0 ||
		this->getInput().compare("-inf") == 0 || this->getInput().compare("+inff") == 0 ||
		this->getInput().compare("-inff") == 0)
		return (NAN_INF);

	else if (this->getInput().length() == 1 &&
			(this->getInput()[0] == '+' || this->getInput()[0] == '-' ||
			this->getInput()[0] == 'f' || this->getInput()[0] == '.'))
		return (CHAR);

	else if (this->getInput().find_first_of("+-") != this->getInput().find_last_of("+-"))
		return (ERROR);

	else if (this->getInput().find_first_not_of("+-0123456789") == std::string::npos)
		return (INT);

	else if (this->getInput().find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (this->getInput().find_first_of(".") != this->getInput().find_last_of(".") ||
			isdigit(this->getInput()[this->getInput().find_first_of(".") + 1]) == false ||
			this->getInput().find_first_of(".") == 0)
			return (ERROR);
		else
			return (DOUBLE);
	}

	else if (this->getInput().find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (this->getInput().find_first_of("f") != this->getInput().find_last_of("f") ||
			this->getInput().find_first_of(".") != this->getInput().find_last_of(".") ||
			this->getInput().find_first_of("f") - this->getInput().find_first_of(".") == 1 ||
			this->getInput().find_first_of(".") == 0 ||
			this->getInput()[this->getInput().find_first_of("f") + 1] != '\0')
			return (ERROR);
		else
			return (FLOAT);
	}

	else if ((this->getInput().length() == 1 && std::isprint(this->getInput()[0])) ||
			(this->getInput().length() == 1 && std::isalpha(this->getInput()[0])))
		return (CHAR);

	else
		return (ERROR);
}

void	Conversion::convertInput()
{
	void	(Conversion::*functions[])(void) = {&Conversion::fromChar, &Conversion::fromInt, &Conversion::fromFloat, &Conversion::fromDouble};
	int		types[] = {CHAR, INT, FLOAT, DOUBLE};

	this->_type = findType();

	if (this->getType() == NAN_INF)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (this->getType() == types[i])
		{
			(this->*functions[i])();
			return;
		}
	}
	throw Conversion::InvalidTypeException();
}

void	Conversion::fromChar()
{
	this->_char = static_cast<unsigned char>(this->getInput()[0]);
	this->_int = static_cast<int>(this->getChar());
	this->_float = static_cast<float>(this->getChar());
	this->_double = static_cast<double>(this->getChar());
}

void	Conversion::fromInt()
{
	this->_int = static_cast<int>(this->getDouble());
	this->_char = static_cast<unsigned char>(this->getInt());
	this->_float = static_cast<float>(this->getDouble());
}

void	Conversion::fromFloat()
{
	this->_float = static_cast<float>(this->getDouble());
	this->_char = static_cast<char>(this->getFloat());
	this->_int = static_cast<int>(this->getFloat());
}

void	Conversion::fromDouble()
{
	this->_char = static_cast<char>(this->getDouble());
	this->_int = static_cast<int>(this->getDouble());
	this->_float = static_cast<float>(this->getDouble());
}

std::ostream	&operator<<(std::ostream &o, Conversion *conversion)
{
	if (conversion->getType() != NAN_INF && conversion->getDouble() <= UCHAR_MAX && conversion->getDouble() >= 0)
	{
		if (isprint(conversion->getChar()))
			o << "char: '" << conversion->getChar() << "'" << std::endl;
		else
			o << "char: Non displayable" << std::endl;
	}
	else
		o << "char: impossible" << std::endl;


	if (conversion->getType() != NAN_INF && conversion->getDouble() >= std::numeric_limits<int>::min() && conversion->getDouble() <= std::numeric_limits<int>::max())
	{
		o << "int: " << conversion->getInt() << std::endl;
	}
	else
		o << "int: impossible" << std::endl;

	if (conversion->getType() != NAN_INF)
	{
		o << "float: " << conversion->getFloat();
		if (conversion->getFloat() - conversion->getInt() == 0)
			o << ".0f" << std::endl;
		else
			o << "f" << std::endl;
	}
	else
	{
		if (conversion->getInput() == "nan" || conversion->getInput() == "nanf")
			o << "float: nanf" << std::endl;
		else if (conversion->getInput()[0] == '+')
			o << "float: +inff" << std::endl;
		else
			o << "float: -inff" << std::endl;
	}

	if (conversion->getType() != NAN_INF)
	{
		o << "double: " << conversion->getDouble();
		if (conversion->getDouble() < std::numeric_limits<int>::min() || conversion->getDouble() > std::numeric_limits<int>::max() ||
			conversion->getDouble() - conversion->getInt() == 0)
		{
			o << ".0" << std::endl;
		}
		else
			o << std::endl;
	}
	else
	{
		if (conversion->getInput() == "nan" || conversion->getInput() == "nanf")
			o << "double: nan" << std::endl;
		else if (conversion->getInput()[0] == '+')
			o << "double: +inf" << std::endl;
		else
			o << "double: -inf" << std::endl;
	}
	return (o);
}
