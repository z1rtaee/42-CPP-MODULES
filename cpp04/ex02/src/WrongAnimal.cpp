#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "WrongAnimal Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : _type(src._type) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "WrongAnimal Copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "WrongAnimal Default destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &obj) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "WrongAnimal Copy assignment called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &obj)
        this->_type = obj.getType();
    return *this;
}

void    WrongAnimal::makeSound() const {
    std::cout << BOLD << MAGENTA << "˚.⋆♪ A Wronganimal sound ecoes... ــــــــﮩ٨ـ" << RESET << std::endl;
}

std::string    WrongAnimal::getType() const {
    return this->_type;
}