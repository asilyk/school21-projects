/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:19:20 by fabet             #+#    #+#             */
/*   Updated: 2022/11/04 19:05:46 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << "Default Form is created!" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (this->_gradeToSign <= 1 || this->_gradeToExecute <= 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToSign >= 150 || this->_gradeToExecute >= 150)
		throw Form::GradeTooLowException();
	std::cout << this->_name << " Form is created!" << std::endl;
}

Form::Form(Form const &src): _name(src.getName()), _isSigned(false), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	std::cout << this->_name << " Form is created with copy constructor!" << std::endl;
	*this = src;
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " is destroyed!" << std::endl;
}

Form	&Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getIsSigned() const
{
	return (this->_isSigned);
}

int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	Form::beSigned(Bureaucrat *bureaucrat)
{
	if (bureaucrat->getGrade() > this->_gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	this->_isSigned = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Error! Grade is too high.");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Error! Grade is too low.");
}

std::ostream	&operator<<(std::ostream &o, Form *form)
{
	o
		<< form->getName() << " form, is signed: " << form->getIsSigned()
		<< ", grade to sign: " << form->getGradeToSign()
		<< ", grade to execute: " << form->getGradeToExecute();
	return (o);
}
