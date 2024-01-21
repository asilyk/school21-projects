/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:32:32 by fabet             #+#    #+#             */
/*   Updated: 2022/11/10 16:06:27 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Test
{
public:
	Test(int n) : number(n) {};
	int	number;
};

std::ostream	&operator<<(std::ostream &o, Test const &test)
{
	o << test.number;
	return (o);
}

int	main()
{
	std::cout << "-----------TEST 1------------" << std::endl;
	{
		int	array[] = {4, 5, 8, 11};
		iter(array, 4, print);
	}
	std::cout << "-----------TEST 2------------" << std::endl;
	{
		char	array[] = {'A', 'c', 'D', '5'};
		iter(array, 4, print);
	}
	std::cout << "-----------TEST 3------------" << std::endl;
	{
		Test	array[] = {Test(5), Test(6),Test(8), Test(11)};
		iter(array, 4, print);
	}

	return (0);
}

// class Awesome
// {
// public:
// 	Awesome() : _n(42) { return; }
// 	int	get() const { return this->_n; }
// private:
// 	int	_n;
// };

// std::ostream &operator<<(std::ostream & o, Awesome const &rhs) { o << rhs.get(); return o; }

// int main()
// {
// 	int		tab[] = { 0, 1, 2, 3, 4 };
// 	Awesome	tab2[5];

// 	iter(tab, 5, print<int>);
// 	iter(tab2, 5, print<Awesome>);

// 	return (0);
// }
