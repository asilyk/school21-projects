/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:11:50 by fabet             #+#    #+#             */
/*   Updated: 2022/11/11 17:25:09 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "-----------TEST 1------------" << std::endl;
	try
	{
		Span sp = Span();
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span is " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span is "<< sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------TEST 2------------" << std::endl;
	try
	{
		Span sp = Span(3);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span is " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span is "<< sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------TEST 3------------" << std::endl;
	try
	{
		Span sp = Span(1);
		sp.addNumber(6);
		std::cout << "Shortest span is " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span is "<< sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------TEST 4------------" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span is " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span is "<< sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------TEST 5------------" << std::endl;
	try
	{
		Span a = Span(10000);
		a.addNumbers(10000);
		std::cout << "Shortest span is " << a.shortestSpan() << std::endl;
		std::cout << "Longest span is " << a.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------TEST 6------------" << std::endl;
	try
	{
		Span a = Span(1000000);
		a.addNumbers(1000000);
		std::cout << "Shortest span is " << a.shortestSpan() << std::endl;
		std::cout << "Longest span is " << a.longestSpan() << std::endl << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
