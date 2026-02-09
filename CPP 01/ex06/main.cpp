#include "Harl.hpp"

int getLevelIndex(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return i;
	}
	return -1;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}
	
	Harl harl;
	std::string level = argv[1];
	int levelIndex = getLevelIndex(level);
	
	if (levelIndex == -1)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}
	
	for (int i = levelIndex; i <= 3; i++)
	{
		switch (i)
		{
			case 0:
				harl.complain("DEBUG");
				break;
			case 1:
				harl.complain("INFO");
				break;
			case 2:
				harl.complain("WARNING");
				break;
			case 3:
				harl.complain("ERROR");
				break;
		}
		if (i < 3)
			std::cout << std::endl;
	}
	
	return 0;
}
