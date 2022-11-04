#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog();
	Dog(const Dog &src);
	virtual ~Dog();

	Dog	&operator=(Dog const &rhs);
	virtual void	makeSound(void) const;
};

#endif
