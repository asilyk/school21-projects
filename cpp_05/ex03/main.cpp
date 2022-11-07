/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:09:55 by fabet             #+#    #+#             */
/*   Updated: 2022/11/07 16:53:26 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "-----------TEST 1------------" << std::endl;
	{
		try
		{
			Intern		*intern = new Intern();
			Form		*form1 =  intern->makeForm("PresidentialPardonForm", "Jone");
			Form		*form2 =  intern->makeForm("RobotomyRequestForm", "Jack");
			Form		*form3 =  intern->makeForm("ShrubberyCreationForm", "tree");
			Bureaucrat	*bureaucrat = new Bureaucrat("Bill", 1);

			form1->beSigned(*bureaucrat);
			form1->execute(*bureaucrat);

			form2->beSigned(*bureaucrat);
			form2->execute(*bureaucrat);

			form3->beSigned(*bureaucrat);
			form3->execute(*bureaucrat);

			delete intern;
			delete bureaucrat;
			delete form1;
			delete form2;
			delete form3;
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
			Intern		*intern = new Intern();
			Form		*form =  intern->makeForm("UnknownForm", "Jone");
			Bureaucrat	*bureaucrat = new Bureaucrat("Bill", 1);

			form->beSigned(*bureaucrat);
			form->execute(*bureaucrat);

			delete intern;
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
