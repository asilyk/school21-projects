/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:44:28 by fabet             #+#    #+#             */
/*   Updated: 2022/11/10 19:27:01 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>

class NoOccurrenceException : public std::exception
{
public:
	virtual const char	*what() const throw()
	{
		return ("No occurrence is found.");
	}
};

template<typename T>
int const	&easyfind(T &container, int const &desired)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), desired);

	if (it == container.end())
		throw (NoOccurrenceException());

	return *it;
}

#endif
