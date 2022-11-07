/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:09:57 by fabet             #+#    #+#             */
/*   Updated: 2022/11/07 14:40:16 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();

	Bureaucrat	&operator=(Bureaucrat const &rhs);

	std::string	getName() const;
	int			getGrade() const;

	void	incrementGrade();
	void	decrementGrade();

	void	signForm(Form &form);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

private:
	const std::string	_name;
	int					_grade;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *bureaucrat);

#endif
