#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
    const int size = 10;
	Animal *animals[size];
	std::cout << BOLD << "##### Creating animal array #####" << RESET << std::endl;
	for (int i = 0; i < size; i++) {
        if (i < size / 2)
            animals[i] = new Dog();
            else
        animals[i] = new Cat();
    }
    
	std::cout << BOLD << "\n############ Sounds ###########" << RESET << std::endl;
	for (int i = 0; i < size; i++)
        animals[i]->makeSound();
    
	std::cout << BOLD<< "\n############ Deleting as Animal* ############" << RESET << std::endl;
	for (int i = 0; i < size; i++)
       delete animals[i];

	std::cout << BOLD << "\n########## Deep copy test (Dog) ##########" << RESET << std::endl;
	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "chase tail");
	Dog copiedDog(originalDog);
	originalDog.getBrain()->setIdea(0, "eepy eepy mimimi");
	std::cout << "originalDog idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "copiedDog idea[0]: " << copiedDog.getBrain()->getIdea(0) << std::endl;

	std::cout << BOLD << "\n########## Deep copy test (Cat) ##########" << RESET << std::endl;
	Cat originalCat;
	originalCat.getBrain()->setIdea(0, "eat fish");
	Cat copiedCat;
	copiedCat = originalCat;
	originalCat.getBrain()->setIdea(0, "sleep on keyboard");
	std::cout << "originalCat idea[0]: " << originalCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "copiedCat idea[0]: " << copiedCat.getBrain()->getIdea(0) << std::endl;

	return 0;
}
