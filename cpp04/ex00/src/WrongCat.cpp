#include "WrongCat.hpp"

WrongCat::WrongCat() {
    _type = "WrongCat";
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "WrongCat Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "WrongCat Copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "WrongCat Default destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

WrongCat  &WrongCat::operator=(const WrongCat &obj) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "WrongCat Copy assignment called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &obj)
        WrongAnimal::operator=(obj);
    return *this;
}

void    WrongCat::makeSound() const {
    std::cout << BOLD << MAGENTA << "˚.⋆♪ Wrong Meow Meow ــﮩ٨ـ ᓚ₍⑅^..^₎♡" << RESET << std::endl;
}
