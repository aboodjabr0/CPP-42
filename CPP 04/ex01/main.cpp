#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ARRAY_SIZE 10

int main()
{
	std::cout << "========== Subject tests ==========" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;
		delete i;
	}

	std::cout << std::endl;
	std::cout << "========== Array of Animals ==========" << std::endl;
	{
		Animal* animals[ARRAY_SIZE];

		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			if (i < ARRAY_SIZE / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
			std::cout << std::endl;
		}

		std::cout << "--- Making sounds ---" << std::endl;
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			std::cout << animals[i]->getType() << ": ";
			animals[i]->makeSound();
		}

		std::cout << std::endl;
		std::cout << "--- Deleting animals ---" << std::endl;
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			delete animals[i];
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "========== Deep copy test (Dog) ==========" << std::endl;
	{
		Dog original;
		original.getBrain()->ideas[0] = "Chase the ball";
		original.getBrain()->ideas[1] = "Eat treats";
		original.getBrain()->ideas[2] = "Go for a walk";

		Dog copy(original);

		std::cout << std::endl;
		std::cout << "Original brain address: " << original.getBrain() << std::endl;
		std::cout << "Copy brain address:     " << copy.getBrain() << std::endl;
		std::cout << "Addresses differ: "
				  << (original.getBrain() != copy.getBrain() ? "YES (deep copy)" : "NO (shallow copy!)")
				  << std::endl;

		std::cout << std::endl;
		std::cout << "Original ideas[0]: " << original.getBrain()->ideas[0] << std::endl;
		std::cout << "Copy ideas[0]:     " << copy.getBrain()->ideas[0] << std::endl;

		copy.getBrain()->ideas[0] = "Dig a hole";
		std::cout << std::endl;
		std::cout << "After modifying copy's idea[0]:" << std::endl;
		std::cout << "Original ideas[0]: " << original.getBrain()->ideas[0] << std::endl;
		std::cout << "Copy ideas[0]:     " << copy.getBrain()->ideas[0] << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "========== Deep copy test (Cat) ==========" << std::endl;
	{
		Cat original;
		original.getBrain()->ideas[0] = "Knock things off the table";
		original.getBrain()->ideas[1] = "Ignore humans";
		original.getBrain()->ideas[2] = "Sleep all day";

		Cat copy;
		copy = original;

		std::cout << std::endl;
		std::cout << "Original brain address: " << original.getBrain() << std::endl;
		std::cout << "Copy brain address:     " << copy.getBrain() << std::endl;
		std::cout << "Addresses differ: "
				  << (original.getBrain() != copy.getBrain() ? "YES (deep copy)" : "NO (shallow copy!)")
				  << std::endl;

		std::cout << std::endl;
		std::cout << "Original ideas[0]: " << original.getBrain()->ideas[0] << std::endl;
		std::cout << "Copy ideas[0]:     " << copy.getBrain()->ideas[0] << std::endl;

		copy.getBrain()->ideas[0] = "Chase a laser pointer";
		std::cout << std::endl;
		std::cout << "After modifying copy's idea[0]:" << std::endl;
		std::cout << "Original ideas[0]: " << original.getBrain()->ideas[0] << std::endl;
		std::cout << "Copy ideas[0]:     " << copy.getBrain()->ideas[0] << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
