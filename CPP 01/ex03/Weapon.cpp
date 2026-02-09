#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_Type = type;
}

const std::string& Weapon::getType(void)
{
	return _Type;
}

void Weapon::setType(std::string newType)
{
	_Type = newType;
}
