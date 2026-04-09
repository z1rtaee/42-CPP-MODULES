#include "Dog.hpp"

Dog::Dog() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Dog Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    _type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Dog Copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    _brain = new Brain(*src._brain);
}

Dog::~Dog() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Dog Default destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    delete _brain;
}

Dog  &Dog::operator=(const Dog &obj) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Dog Copy assignment called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &obj) {
        Animal::operator=(obj);
        delete _brain;
        _brain = new Brain(*obj._brain);
    }
    return *this;
}

void    Dog::makeSound() const {
    std::cout << BOLD << MAGENTA << "˚.⋆♪  Bark Bark ــﮩ٨ـ ˚ ⋅૮₍ › ˕ ‹ ₎ა ⋅˚⋅ ♡" << RESET << std::endl;
}

Brain* Dog::getBrain() const {
    return _brain;
}