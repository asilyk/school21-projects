#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor was called." << std::endl;
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor was called." << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat destructor was called." << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat meows." << std::endl;
}