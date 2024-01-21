/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:31:47 by fabet             #+#    #+#             */
/*   Updated: 2022/11/07 17:01:11 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Intern is created!" << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << " Intern is created with copy constructor!" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern is destroyed!" << std::endl;
}

Intern	&Intern::operator=(Intern const &rhs)
{
	if (this != &rhs)
		return (*this);
	return (*this);
}

static Form	*makePresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static Form	*makeRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form	*makeShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::makeForm(std::string formName, std::string target) const
{
	Form *(*makeForms[])(const std::string target) = {&makePresidentialPardonForm, &makeRobotomyRequestForm, &makeShrubberyCreationForm};
	std::string formNames[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << "." << std::endl;
			return (makeForms[i](target));
		}
	}
	throw Intern::UnknownFormException();
	return (NULL);
}

const char*	Intern::UnknownFormException::what() const throw()
{
	return ("Error! Form is unknown.");
}
