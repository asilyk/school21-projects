/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:27:35 by fabet             #+#    #+#             */
/*   Updated: 2022/11/08 19:39:57 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main()
{
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		Base *base = generate();
		if (base == NULL)
			return (1);
		else
		{
			std:: cout << "Test " << i << std::endl;
			identify(base);
			identify(*base);
			delete (base);
			std::cout << std::endl;
		}
	}

	std:: cout << "Test 10" << std::endl;
	Base *a = new A();
	identify(a);
	identify(*a);
	delete a;
	std::cout << std::endl;

	std:: cout << "Test 11" << std::endl;
	Base *b = new B();
	identify(b);
	identify(*b);
	delete b;
	std::cout << std::endl;

	std:: cout << "Test 12" << std::endl;
	Base *c = new C();
	identify(c);
	identify(*c);
	delete c;

	return (0);
}
