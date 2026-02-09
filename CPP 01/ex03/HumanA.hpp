#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	std::string _Name;
	Weapon& _Weapon;

public:
	HumanA(std::string name, Weapon& weapon);
	
	void attack(void);
};

#endif
