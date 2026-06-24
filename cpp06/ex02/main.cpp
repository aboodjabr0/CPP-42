#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 6; ++i)
	{
		Base* obj = generate();
		std::cout << "identify(pointer): ";
		identify(obj);
		std::cout << "identify(reference): ";
		identify(*obj);
		delete obj;
	}
	return 0;
}
