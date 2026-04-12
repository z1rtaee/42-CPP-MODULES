#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Cure Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src) {
    (void)src;
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Cure Copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Cure::~Cure() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Cure Default destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Cure &Cure::operator=(const Cure &obj) {
    (void)obj;
    return *this;
}

AMateria    *Cure::clone(void) const {
    return (new Cure(*this));
}

void    Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
