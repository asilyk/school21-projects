/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:09:59 by fabet             #+#    #+#             */
/*   Updated: 2022/11/07 14:40:09 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Default Bureaucrat is created!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (this->getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->getName() << " Bureaucrat is created!" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	std::cout << this->getName() << " Bureaucrat is created with copy constructor!" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->getName() << " is destroyed!" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " bureaucrat signed " << form.getName() << " form." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr
			<< this->getName() << " bureaucrat  couldn’t sign  "
			<< form.getName() << " form because: "
			<< e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error! Grade is too high.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error! Grade is too low.");
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *bureaucrat)
{
	o << bureaucrat->getName() << ",  bureaucrat grade " << bureaucrat->getGrade() << ".";
	return (o);
}
