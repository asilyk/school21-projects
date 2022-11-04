#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor was called." << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor was called." << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain destructor was called." << std::endl;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	if (this != &rhs)
		std::copy(rhs._ideas, rhs._ideas + 100, this->_ideas);
	return (*this);
}
