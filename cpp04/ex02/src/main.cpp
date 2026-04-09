#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    std::cout << BOLD << "\n########## CORRECT POLYMORPHISM ##########\n" << RESET << std::endl;

    //const AAnimal* meta = new AAnimal();
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound(); // Cat
    j->makeSound(); // Dog
    //meta->makeSound(); // Animal

    delete i;
    delete j;
    //delete meta;

    std::cout << BOLD << "\n########## WRONG POLYMORPHISM ##########\n" << RESET << std::endl;

    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* w = new WrongCat();

    std::cout << w->getType() << std::endl;

    w->makeSound();    

    delete w;
    delete wmeta;

    return 0;
}