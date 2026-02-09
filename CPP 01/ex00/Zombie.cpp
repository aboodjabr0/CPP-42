#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName)
{
	_Name = zombieName;
}

Zombie::~Zombie(void)
{
	std::cout << _Name << " is destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
