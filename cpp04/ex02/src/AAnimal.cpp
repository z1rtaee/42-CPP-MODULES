#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "AAnimal Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) : _type(src._type) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "AAnimal Copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "AAnimal Default destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

AAnimal  &AAnimal::operator=(const AAnimal &obj) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "AAnimal Copy assignment called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &obj)
        this->_type = obj.getType();
    return *this;
}

void    AAnimal::makeSound() const {
    std::cout << BOLD << MAGENTA << "˚.⋆♪ An AAnimal sound ecoes... ــــــــﮩ٨ـ" << RESET << std::endl;
}

std::string    AAnimal::getType() const {
    return this->_type;
}
