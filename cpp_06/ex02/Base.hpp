/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:04:58 by fabet             #+#    #+#             */
/*   Updated: 2022/11/08 19:31:59 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

class Base
{
public:
	virtual ~Base();
};

Base	*generate();

void	identify(Base *p);

void	identify(Base &p);

#endif
