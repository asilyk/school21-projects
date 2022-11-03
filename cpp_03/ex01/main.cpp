#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	trap("Jack");

	for (int i = 0; i < 5; i++)
	{
		trap.attack("Ben");
		trap.takeDamage(10);
		trap.beRepaired(5);
	}
	trap.guardGate();
	trap.guardGate();
	trap.guardGate();
	return (0);
}
