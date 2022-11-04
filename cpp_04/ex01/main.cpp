#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal	*animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << animals[i]->getType()<< std::endl;
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; i++)
		delete animals[i];

	return (0);
}
