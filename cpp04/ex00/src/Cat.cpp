#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Cat Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Cat Copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Cat::~Cat() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Cat Default destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Cat  &Cat::operator=(const Cat &obj) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Cat Copy assignment called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &obj)
        Animal::operator=(obj);
    return *this;
}

void    Cat::makeSound() const {
    std::cout << BOLD << MAGENTA << "˚.⋆♪  Meow Meow ــﮩ٨ـ ᓚ₍⑅^..^₎♡" << RESET << std::endl;
}
