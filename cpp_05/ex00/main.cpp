/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:09:55 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 17:12:51 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat	*bureaucrat = new Bureaucrat("Ben", 50);
			std::cout << bureaucrat << std::endl;
			bureaucrat->decrementGrade();
			std::cout << bureaucrat << std::endl;
			bureaucrat->incrementGrade();
			std::cout << bureaucrat << std::endl;
			delete bureaucrat;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat	*bureaucrat = new Bureaucrat("Jonny", 0);
			std::cout << bureaucrat << std::endl;
			delete bureaucrat;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat	*bureaucrat = new Bureaucrat("Steve", 159);
			std::cout << bureaucrat << std::endl;
			delete bureaucrat;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat	*bureaucrat = new Bureaucrat("Steve", 150);
			std::cout << bureaucrat << std::endl;
			bureaucrat->decrementGrade();
			std::cout << bureaucrat << std::endl;
			delete bureaucrat;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat	*bureaucrat = new Bureaucrat("Steve", 1);
			std::cout << bureaucrat << std::endl;
			bureaucrat->incrementGrade();
			std::cout << bureaucrat << std::endl;
			delete bureaucrat;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
