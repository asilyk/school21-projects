#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	trap("Jack");

	for (int i = 0; i < 5; i++)
	{
		trap.attack("Ben");
		trap.takeDamage(10);
		trap.beRepaired(5);
	}
	trap.highFivesGuys();
	return (0);
}
