/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:09:55 by fabet             #+#    #+#             */
/*   Updated: 2022/11/07 16:03:08 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "-----------TEST 1------------" << std::endl;
	{
		try
		{
			Form		*form =  new ShrubberyCreationForm("new");
			Bureaucrat	*bureaucrat = new Bureaucrat("Bill", 100);

			form->beSigned(*bureaucrat);
			form->execute(*bureaucrat);

			delete bureaucrat;
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "-----------TEST 2------------" << std::endl;
	{
		try
		{
			Form		*form =  new ShrubberyCreationForm("new");
			Bureaucrat	*bureaucrat = new Bureaucrat("Bill", 100);

			form->execute(*bureaucrat);

			delete bureaucrat;
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "-----------TEST 3------------" << std::endl;
	{
		try
		{
			Form		*form =  new ShrubberyCreationForm("new");
			Bureaucrat	*bureaucrat = new Bureaucrat("Bill", 138);

			form->beSigned(*bureaucrat);
			form->execute(*bureaucrat);

			delete bureaucrat;
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "-----------TEST 4------------" << std::endl;
	{
		try
		{
			Form		*form =  new ShrubberyCreationForm("new");
			Bureaucrat	*bureaucrat = new Bureaucrat("Bill", 10);

			bureaucrat->signForm(*form);
			bureaucrat->executeForm(*form);

			delete bureaucrat;
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "-----------TEST 5------------" << std::endl;
	{
		try
		{
			Form		*form =  new ShrubberyCreationForm("new");
			Bureaucrat	*bureaucrat = new Bureaucrat("Bill", 150);

			bureaucrat->signForm(*form);
			bureaucrat->executeForm(*form);

			delete bureaucrat;
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "-----------TEST 6------------" << std::endl;
	{
		try
		{
			Form		*form =  new ShrubberyCreationForm("new");
			Bureaucrat	*bureaucrat = new Bureaucrat("Bill", 10);

			bureaucrat->executeForm(*form);

			delete bureaucrat;
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "-----------TEST 7------------" << std::endl;
	{
		try
		{
			Form		*form =  new RobotomyRequestForm("new");
			Bureaucrat	*bureaucrat = new Bureaucrat("Bill", 10);

			form->beSigned(*bureaucrat);
			form->execute(*bureaucrat);
			form->execute(*bureaucrat);
			form->execute(*bureaucrat);
			form->execute(*bureaucrat);

			delete bureaucrat;
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "-----------TEST 8------------" << std::endl;
	{
		try
		{
			Form		*form =  new PresidentialPardonForm("new");
			Bureaucrat	*bureaucrat = new Bureaucrat("Bill", 1);

			form->beSigned(*bureaucrat);
			form->execute(*bureaucrat);

			delete bureaucrat;
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
