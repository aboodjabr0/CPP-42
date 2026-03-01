#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "========== Subject tests ==========" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "========== Wrong classes tests ==========" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongCat;

	std::cout << std::endl;
	std::cout << "========== Stack objects tests ==========" << std::endl;
	Dog dog;
	Cat cat;
	Animal animal;

	std::cout << "Dog type: " << dog.getType() << std::endl;
	std::cout << "Cat type: " << cat.getType() << std::endl;
	std::cout << "Animal type: \"" << animal.getType() << "\"" << std::endl;
	dog.makeSound();
	cat.makeSound();
	animal.makeSound();

	std::cout << std::endl;
	std::cout << "========== Copy / Assignment tests ==========" << std::endl;
	Dog dog2(dog);
	Cat cat2;
	cat2 = cat;

	std::cout << "dog2 type: " << dog2.getType() << std::endl;
	std::cout << "cat2 type: " << cat2.getType() << std::endl;
	dog2.makeSound();
	cat2.makeSound();

	std::cout << std::endl;
	std::cout << "========== Polymorphism via reference ==========" << std::endl;
	const Animal &animalRefDog = dog;
	const Animal &animalRefCat = cat;

	std::cout << "Ref Dog type: " << animalRefDog.getType() << std::endl;
	std::cout << "Ref Cat type: " << animalRefCat.getType() << std::endl;
	animalRefDog.makeSound();
	animalRefCat.makeSound();

	std::cout << std::endl;
	std::cout << "========== WrongCat as direct object ==========" << std::endl;
	WrongCat directWrongCat;
	directWrongCat.makeSound();

	std::cout << std::endl;
	std::cout << "========== Destructors ==========" << std::endl;
	return 0;
}
