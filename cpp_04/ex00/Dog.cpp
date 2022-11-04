#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor was called." << std::endl;
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor was called." << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog destructor was called." << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog barks." << std::endl;
}