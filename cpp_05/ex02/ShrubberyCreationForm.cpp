/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:14:58 by fabet             #+#    #+#             */
/*   Updated: 2022/11/07 03:26:16 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("target")
{
	std::cout << "Default ShrubberyCreationForm is created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	if (this->getGradeToSign() < 1 || this->getGradeToExecute() < 1)
		throw Form::GradeTooHighException();
	if (this->getGradeToSign() > 150 || this->getGradeToExecute() > 150)
		throw Form::GradeTooLowException();
	std::cout << this->getName() << " ShrubberyCreationForm is created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	std::cout << this->getName() << " ShrubberyCreationForm is created with copy constructor!" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << this->getName() << " is destroyed!" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this == &src)
		return *this;
	return *this;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

static void	drawTree(std::string target)
{
	std::ofstream	targetFile;
	targetFile.open(target.append("_shrubbery"), std::ifstream::out);
	if (!targetFile.is_open())
		throw Form::OFStreamException();
	targetFile
				<< "     ccee88oo" << std::endl
				<< "C8O8O8Q8PoOb o8oo" << std::endl
				<< "dOB69QO8PdUOpugoO9bD" << std::endl
				<< "CgggbU8OU qOp qOdoUOdcb" << std::endl
				<< " 6OuU  /p u gcoUodpP" << std::endl
				<< "    \\\\//  /douUP" << std::endl
				<< "       \\\\///" << std::endl
				<< "       |||/|" << std::endl
				<< "       |||\\" << std::endl
				<< "       |||||" << std::endl
				<< ".....//|||||...." << std::endl;
	targetFile.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	isFormReadyToExecute(executor);
	drawTree(this->getTarget());
}
