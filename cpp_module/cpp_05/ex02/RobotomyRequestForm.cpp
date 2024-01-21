/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:36:01 by fabet             #+#    #+#             */
/*   Updated: 2022/11/07 15:43:05 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("target")
{
	std::cout << "Default RobotomyRequestForm is created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	if (this->getGradeToSign() < 1 || this->getGradeToExecute() < 1)
		throw Form::GradeTooHighException();
	if (this->getGradeToSign() > 150 || this->getGradeToExecute() > 150)
		throw Form::GradeTooLowException();
	std::cout << this->getName() << " RobotomyRequestForm is created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form("RobotomyRequestForm", 72, 45), _target(src.getTarget())
{
	std::cout << this->getName() << " RobotomyRequestForm is created with copy constructor!" << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << this->getName() << " is destroyed!" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
		return *this;
	return *this;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	isFormReadyToExecute(executor);
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy of " <<this->getTarget() << " failed." << std::endl;

}
