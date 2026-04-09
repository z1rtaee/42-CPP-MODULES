#include "Cat.hpp"

Cat::Cat() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Cat Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Cat Copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    _brain = new Brain(*src._brain);
}

Cat::~Cat() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Cat Default destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    delete _brain;
}

Cat  &Cat::operator=(const Cat &obj) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Cat Copy assignment called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &obj) {
        Animal::operator=(obj);
        delete _brain;
        _brain = new Brain(*obj._brain);
    }
    return *this;
}

void    Cat::makeSound() const {
    std::cout << BOLD << MAGENTA << "˚.⋆♪  Meow Meow ــﮩ٨ـ ᓚ₍⑅^..^₎♡" << RESET << std::endl;
}

Brain* Cat::getBrain() const {
    return _brain;
}