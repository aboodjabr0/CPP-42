#include "Zombie.hpp"

int main(void)
{
	std::cout << "=== Creating Zombie on the HEAP ===" << std::endl;
	Zombie* heapZombie = newZombie("HeapWalker");
	heapZombie->announce();
	
	std::cout << "\n=== Creating Zombie on the STACK ===" << std::endl;
	randomChump("StackBiter");
	
	std::cout << "\n=== Creating another Stack Zombie ===" << std::endl;
	randomChump("QuickZombie");
	
	std::cout << "\n=== Manual deletion of Heap Zombie ===" << std::endl;
	delete heapZombie;
	
	std::cout << "\n=== Program ends ===" << std::endl;
	return 0;
}
