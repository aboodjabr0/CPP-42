#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _Name(name), _Weapon(weapon)
{
}

void HumanA::attack(void)
{
	std::cout << _Name << " attacks with their " << _Weapon.getType() << std::endl;
}
