#include "AMateria.hpp"

AMateria::AMateria() : _type("") {
}

AMateria::AMateria(const AMateria &src) {
    if (this != &src)
        *this = src;
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
    (void)target;
}

std::string const &AMateria::getType() const {
    return this->_type;
}
