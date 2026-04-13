#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
}

Ice::Ice(const Ice &src) : AMateria(src) {
}

Ice::~Ice() {
}

Ice &Ice::operator=(const Ice &obj) {
    (void)obj;
    return *this;
}

AMateria    *Ice::clone(void) const {
    std::cout << BOLD << MAGENTA << "> An Ice materia is cloned" << RESET << std::endl;
    return (new Ice(*this));
}

void    Ice::use(ICharacter &target) {
    (void)target;
    std::cout << BOLD << MAGENTA << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
