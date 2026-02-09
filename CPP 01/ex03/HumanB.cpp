#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_Name = name;
	_Weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
	_Weapon = &weapon;
}

void HumanB::attack(void)
{
	if (_Weapon == NULL)
	{
		std::cout << _Name << " has no weapon!" << std::endl;
	}
	else
	{
		std::cout << _Name << " attacks with their " << _Weapon->getType() << std::endl;
	}
}
