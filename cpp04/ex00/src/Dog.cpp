#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Dog Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Dog Copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Dog::~Dog() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Dog Default destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Dog  &Dog::operator=(const Dog &obj) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Dog Copy assignment called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &obj)
        Animal::operator=(obj);
    return *this;
}

void    Dog::makeSound() const {
    std::cout << BOLD << MAGENTA << "˚.⋆♪  Bark Bark ــﮩ٨ـ ˚ ⋅૮₍ › ˕ ‹ ₎ა ⋅˚⋅ ♡" << RESET << std::endl;
}
