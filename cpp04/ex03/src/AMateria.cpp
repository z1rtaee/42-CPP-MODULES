#include "AMateria.hpp"

AMateria::AMateria() : _type("") {
}

AMateria::AMateria(const AMateria &src) : _type(src._type) {
}

AMateria::AMateria(std::string const &type) : _type(type) {
}

AMateria::~AMateria() {
}

AMateria &AMateria::operator=(const AMateria &obj) {
    (void)obj;
    return *this;
}

void    AMateria::use(ICharacter &target) {
    std::cout << BOLD << MAGENTA << "> neutral materia shimmers around " << target.getName() << RESET << std::endl;
    (void)target;
}

std::string const &AMateria::getType() const {
    return this->_type;
}
