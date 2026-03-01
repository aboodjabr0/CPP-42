#include "Zombie.hpp"

int main(void)
{
	int hordeSize = 5;
	
	std::cout << "=== Creating a Horde of " << hordeSize << " Zombies ===" << std::endl;
	Zombie* horde = zombieHorde(hordeSize, "Stalkers");
	
	std::cout << "\n=== Each Zombie Announces ===" << std::endl;
	for (int i = 0; i < hordeSize; i++)
	{
		std::cout << "Zombie " << i << ": ";
		horde[i].announce();
	}
	
	std::cout << "\n=== Deleting the Stalkers ===" << std::endl;
	delete[] horde;
    
	return 0;
}
