/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:00:01 by fabet             #+#    #+#             */
/*   Updated: 2022/11/08 14:13:51 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <string>
# include <iostream>

typedef		int	type;
# define	NAN_INF	1
# define	ERROR	2
# define	CHAR	3
# define	INT		4
# define	FLOAT	5
# define	DOUBLE	6

class Conversion
{
public:
	Conversion();
	Conversion(const std::string input);
	Conversion(const Conversion &src);
	~Conversion();

	Conversion &operator=(const Conversion &rhs);

	std::string	getInput() const;
	type		getType() const;
	char		getChar() const;
	int			getInt() const;
	float		getFloat() const;
	double		getDouble() const;

	class InvalidTypeException : public std::exception
	{
	public:
		virtual const char	*what() const throw();
	};

private:
	const std::string	_input;
	type				_type;
	char				_char;
	int					_int;
	float				_float;
	double				_double;

	type	findType();
	void	convertInput();

	void	fromChar();
	void	fromInt();
	void	fromFloat();
	void	fromDouble();
};

std::ostream	&operator<<(std::ostream &o, Conversion *conversion);

#endif
