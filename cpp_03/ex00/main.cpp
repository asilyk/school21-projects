#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	trap("Jack");

	for (int i = 0; i < 9; i++)
	{
		trap.attack("Ben");
		trap.takeDamage(2);
		trap.beRepaired(2);
	}
	return (0);
}
