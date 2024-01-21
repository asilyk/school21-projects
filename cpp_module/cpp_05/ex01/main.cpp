/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:09:55 by fabet             #+#    #+#             */
/*   Updated: 2022/11/07 14:25:38 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "-----------TEST 1------------" << std::endl;
	{
		try
		{
			Bureaucrat	*bureaucrat = new Bureaucrat("Ben", 50);
			Form		*form1 = new Form("DOC1", 60, 60);
			Form		*form2 = new Form("DOC2", 30, 30);
			Form		*form3 = new Form("DOC3", 60, 60);

			std::cout << bureaucrat << std::endl;
			std::cout << form1 << std::endl;
			std::cout << form2 << std::endl;
			std::cout << form3 << std::endl;

			bureaucrat->signForm(*form1);
			bureaucrat->signForm(*form2);
			form3->beSigned(*bureaucrat);
			std::cout << form3 << std::endl;

			delete bureaucrat;
			delete form1;
			delete form2;
			delete form3;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "-----------TEST 2------------" << std::endl;
	{
		try
		{
			Form		*form = new Form("DOC", 160, 60);

			std::cout << form << std::endl;

			delete form;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "-----------TEST 3------------" << std::endl;
	{
		try
		{
			Form		*form = new Form("DOC", 0, 60);

			std::cout << form << std::endl;

			delete form;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "-----------TEST 4------------" << std::endl;
	{
		try
		{
			Bureaucrat	*bureaucrat = new Bureaucrat("Ben", 50);
			Form		*form = new Form("DOC", 10, 20);

			std::cout << bureaucrat << std::endl;
			std::cout << form << std::endl;
			form->beSigned(*bureaucrat);
			std::cout << form << std::endl;

			delete bureaucrat;
			delete form;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
