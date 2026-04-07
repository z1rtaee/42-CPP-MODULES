#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << BOLD << "\n########## CORRECT POLYMORPHISM ##########\n" << RESET << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound(); // Cat
    j->makeSound(); // Dog
    meta->makeSound(); // Animal

    delete i;
    delete j;
    delete meta;

    std::cout << BOLD << "\n########## WRONG POLYMORPHISM ##########\n" << RESET << std::endl;

    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* w = new WrongCat();

    std::cout << w->getType() << std::endl;

    w->makeSound();     // ❌ SHOULD call WrongAnimal (this is the point)
    wmeta->makeSound(); // WrongAnimal

    delete w;
    delete wmeta;

    return 0;
}