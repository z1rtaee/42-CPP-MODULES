#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Ice Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Ice Copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Ice::~Ice() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Ice Default destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Ice &Ice::operator=(const Ice &obj) {
    (void)obj;
    return *this;
}

AMateria    *Ice::clone(void) const {
    return (new Ice(*this));
}

void    Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
