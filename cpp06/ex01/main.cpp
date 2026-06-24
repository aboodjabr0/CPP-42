#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data original;
	original.value = 42;
	original.name  = "test";
	original.score = 9.81;

	std::cout << "Original pointer : " << &original << "\n";
	std::cout << "Data: value=" << original.value
			  << " name=" << original.name
			  << " score=" << original.score << "\n";

	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized (raw) : " << raw << "\n";

	Data* restored = Serializer::deserialize(raw);
	std::cout << "Restored pointer : " << restored << "\n";

	if (restored == &original)
		std::cout << "Pointers match: OK\n";
	else
		std::cout << "Pointers differ: FAIL\n";

	std::cout << "Data: value=" << restored->value
			  << " name=" << restored->name
			  << " score=" << restored->score << "\n";

	return 0;
}
