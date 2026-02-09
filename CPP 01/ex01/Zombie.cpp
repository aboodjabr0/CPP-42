#include "Zombie.hpp"

Zombie::Zombie()
{
	_Name = "";
}

Zombie::~Zombie(void)
{
	std::cout << _Name << " is destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_Name = name;
}
