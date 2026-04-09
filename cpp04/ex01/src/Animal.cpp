#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Animal Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Animal::Animal(const Animal &src) : _type(src._type) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Animal Copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Animal::~Animal() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Animal Default destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Animal  &Animal::operator=(const Animal &obj) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Animal Copy assignment called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &obj)
        this->_type = obj.getType();
    return *this;
}

void    Animal::makeSound() const {
    std::cout << BOLD << MAGENTA << "˚.⋆♪ An animal sound ecoes... ــــــــﮩ٨ـ" << RESET << std::endl;
}

std::string    Animal::getType() const {
    return this->_type;
}