#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
}

Cure::Cure(const Cure &src) : AMateria(src) {
    (void)src;
}

Cure::~Cure() {
}

Cure &Cure::operator=(const Cure &obj) {
    (void)obj;
    return *this;
}

AMateria    *Cure::clone(void) const {
    std::cout << BOLD << MAGENTA << "> A Cure materia is cloned" << RESET << std::endl;
    return (new Cure(*this));
}

void    Cure::use(ICharacter &target) {
    std::cout << BOLD << MAGENTA << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}