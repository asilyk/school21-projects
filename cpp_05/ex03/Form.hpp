/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:19:18 by fabet             #+#    #+#             */
/*   Updated: 2022/11/07 13:16:03 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(Form const &src);
	virtual ~Form();

	Form	&operator=(Form const &rhs);

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void			beSigned(Bureaucrat const &bureaucrat);
	void			isFormReadyToExecute(Bureaucrat const &executor) const;
	virtual void	execute(Bureaucrat const &executor) const = 0;

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
	class FormIsNotSignedException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
	class OFStreamException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &o, Form *form);

#endif
