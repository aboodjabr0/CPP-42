#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string _Name;

public:
	Zombie(std::string zombieName);
	~Zombie(void);
	
	void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
