#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &src);
	~WrongCat();

	WrongCat	&operator=(WrongCat const &rhs);
	void	makeSound(void) const;
};

#endif
