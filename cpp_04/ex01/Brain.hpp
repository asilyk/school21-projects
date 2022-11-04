#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
public:
	Brain();
	Brain(const Brain &src);
	~Brain();

	Brain	&operator=(Brain const &rhs);

private:
	std::string _ideas[100];
};

#endif
