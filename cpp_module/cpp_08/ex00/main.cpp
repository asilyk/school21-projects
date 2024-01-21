/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:44:31 by fabet             #+#    #+#             */
/*   Updated: 2022/11/10 19:19:17 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

int	main()
{
	try
	{
		std::array<int, 4> a = {5, 11, -2, 9};
		std:: cout << easyfind(a, -2) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::vector<int> v;
		v.push_back(5);
		v.push_back(11);
		v.push_back(-2);
		v.push_back(9);
		std:: cout << easyfind(v, 11) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::deque<int> d;
		d.push_back(5);
		d.push_back(11);
		d.push_back(-2);
		d.push_back(9);
		std:: cout << easyfind(d, 5) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::forward_list<int> fl;
		fl.push_front(9);
		fl.push_front(-2);
		fl.push_front(11);
		fl.push_front(5);
		std:: cout << easyfind(fl, -2) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::list<int> l;
		l.push_back(5);
		l.push_back(11);
		l.push_back(-2);
		l.push_back(9);
		std:: cout << easyfind(l, 9) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
