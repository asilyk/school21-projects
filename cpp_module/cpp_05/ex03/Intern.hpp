/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:31:49 by fabet             #+#    #+#             */
/*   Updated: 2022/11/07 16:59:21 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern const &src);
	~Intern();

	Intern	&operator=(Intern const &rhs);

	Form	*makeForm(std::string formName, std::string target) const;

	class UnknownFormException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

#endif
