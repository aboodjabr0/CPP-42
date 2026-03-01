#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

static void	printSeparator(const std::string& label)
{
	std::cout << std::endl;
	std::cout << "========== " << label << " ==========" << std::endl;
}

int	main(void)
{

	printSeparator("Test 1: ClapTrap basic construction & destruction");
	{
		ClapTrap	a("Alice");
		ClapTrap	b(a);
		ClapTrap	c("Charlie");
		c = a;
	}

	printSeparator("Test 2: ClapTrap normal attack & repair");
	{
		ClapTrap	hero("Hero");

		hero.attack("wall");
		hero.beRepaired(3);
		hero.takeDamage(10);
		hero.attack("wall");
	}

	printSeparator("Test 3: ScavTrap construction chaining (ClapTrap built first)");
	{
		ScavTrap	sc("Scavvy");
		// Destruction at end of scope fires ScavTrap dtor first, then ClapTrap dtor
	}

	printSeparator("Test 4: ScavTrap default constructor & copy");
	{
		ScavTrap	a;
		ScavTrap	b(a);           // copy constructor
		ScavTrap	c("Copier");
		c = a;                      // copy assignment
	}

	printSeparator("Test 5: ScavTrap attack (own message) & guardGate");
	{
		ScavTrap	sc("Guardian");

		sc.attack("invader");
		sc.guardGate();
		sc.beRepaired(10);          // ClapTrap::beRepaired, ScavTrap energy pool
		sc.takeDamage(50);
		sc.attack("invader");
	}

	printSeparator("Test 6: ScavTrap energy drain (50 actions then blocked)");
	{
		ScavTrap	robot("Scrap");

		for (int i = 0; i < 50; i++)
			robot.attack("wall");

		robot.attack("wall");       // 51st -- must be blocked
		robot.guardGate();          // guardGate costs no energy, always works
	}

	printSeparator("Test 7: ScavTrap death prevents actions");
	{
		ScavTrap	victim("FragTrap");

		victim.takeDamage(100);     // lethal
		victim.attack("nobody");
		victim.beRepaired(99);
		victim.guardGate();         // guardGate has no HP/energy cost, still works
	}

	std::cout << std::endl;
	return (0);
}
