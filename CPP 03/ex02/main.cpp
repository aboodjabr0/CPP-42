#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

static void	printSeparator(const std::string& label)
{
	std::cout << std::endl;
	std::cout << "========== " << label << " ==========" << std::endl;
}

int	main(void)
{
	// ---- ClapTrap tests (kept from ex00) ----

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
		hero.attack("wall");    // dead, blocked
	}

	// ---- ScavTrap tests ----

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

	// ---- FragTrap tests ----

	printSeparator("Test 8: FragTrap construction chaining (ClapTrap built first)");
	{
		FragTrap	fg("Frag");
		// Destruction: FragTrap dtor first, then ClapTrap dtor
	}

	printSeparator("Test 9: FragTrap default constructor & copy");
	{
		FragTrap	a;
		FragTrap	b(a);		// copy constructor
		FragTrap	c("FragC");
		c = a;				// copy assignment
	}

	printSeparator("Test 10: FragTrap attack (own message) & highFivesGuys");
	{
		FragTrap	fg("Pineapple");

		fg.attack("enemy");
		fg.highFivesGuys();
		fg.beRepaired(5);
		fg.takeDamage(60);
		fg.attack("enemy");
		fg.highFivesGuys();
	}

	printSeparator("Test 11: FragTrap energy drain (100 actions then blocked)");
	{
		FragTrap	robot("Grenadier");

		for (int i = 0; i < 100; i++)
			robot.attack("wall");

		robot.attack("wall");		// 101st -- must be blocked
		robot.highFivesGuys();		// no energy cost, always works
	}

	printSeparator("Test 12: FragTrap death prevents actions");
	{
		FragTrap	victim("GlassJaw");

		victim.takeDamage(100);		// lethal
		victim.attack("nobody");
		victim.beRepaired(99);
		victim.highFivesGuys();		// no HP/energy cost, always works
	}

	std::cout << std::endl;
	return (0);
}
