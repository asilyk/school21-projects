/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:07:16 by fabet             #+#    #+#             */
/*   Updated: 2022/11/10 16:40:06 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
public:
	Array();
	Array(int size);
	Array(const Array &src);
	~Array();

	Array	&operator=(const Array &src);
	T	&operator[](int index) const;

	int	getSize() const;

	class InvalidIndexException : public std::exception
	{
	public:
		virtual const char	*what() const throw();
	};

private:
	T				*_array;
	int				_size;
};

#endif
