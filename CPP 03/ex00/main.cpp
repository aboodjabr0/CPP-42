#include "ClapTrap.hpp"
#include <iostream>

static void	printSeparator(const std::string& label)
{
	std::cout << std::endl;
	std::cout << "========== " << label << " ==========" << std::endl;
}

int	main(void)
{
	printSeparator("Test 1: Basic construction & destruction");
	{
		ClapTrap	a("Alice");
		ClapTrap	b;
		ClapTrap	c(a);       // copy constructor
		ClapTrap	d("Dave");
		d = a;                  // copy assignment
	} // destructors fire here

	printSeparator("Test 2: Normal attack & repair");
	{
		ClapTrap	hero("Hero");
		ClapTrap	dummy("Dummy");

		hero.attack("Dummy");
		dummy.takeDamage(0);   // 0-damage hit (edge case)
		hero.beRepaired(5);
		hero.attack("Dummy");
		dummy.takeDamage(10);
	}

	printSeparator("Test 3: Energy drain (10 actions then no more)");
	{
		ClapTrap	robot("R0B0T");

		// 10 attacks exhaust all energy
		for (int i = 0; i < 10; i++)
			robot.attack("wall");

		// 11th attempt must be blocked
		robot.attack("wall");
		robot.beRepaired(5);
	}

	printSeparator("Test 4: Death prevents actions");
	{
		ClapTrap	victim("Victim");

		victim.takeDamage(10); // lethal hit
		victim.attack("nobody");
		victim.beRepaired(99);
		victim.takeDamage(1);  // already dead
	}

	printSeparator("Test 5: Overkill damage clamps to 0 HP");
	{
		ClapTrap	tank("Tank");

		tank.takeDamage(9999); // way more than 10 HP
		tank.attack("nobody"); // should be blocked (dead)
	}

	std::cout << std::endl;
	return (0);
}
