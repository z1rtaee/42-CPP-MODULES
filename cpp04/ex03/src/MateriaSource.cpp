#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        _memory[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &src) {
    for (int i = 0; i < 4; i++) {
        _memory[i] = NULL;
    }
    *this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj) {
    if (this == &obj) {
        return *this;
    }
    for (int i = 0; i < 4; i++) {
        if (_memory[i]) {
            delete _memory[i];
            _memory[i] = NULL;
        }
        if (obj._memory[i]) {
            _memory[i] = obj._memory[i]->clone();
        } else {
            _memory[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_memory[i]) {
            std::cout << MAGENTA << ".* " << BOLD << "Forgetting learned materia in slot " << i << RESET << std::endl;
            delete _memory[i];
            _memory[i] = NULL;
        }
    }
}

void    MateriaSource::learnMateria(AMateria *obj) {
    if (!obj) {
        std::cout << BOLD << MAGENTA << "> MateriaSource cannot learn an empty spell" << RESET << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!_memory[i]) {
            _memory[i] = obj->clone();
            std::cout << BOLD << MAGENTA << "> MateriaSource learned [" << obj->getType() << "] in slot " << i << RESET << std::endl;
            delete obj;
            return;
        }
    }
    std::cout << BOLD << MAGENTA << "> MateriaSource memory is full. [" << obj->getType() << "] is ignored" << RESET << std::endl;
    delete obj;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_memory[i] && _memory[i]->getType() == type) {
            std::cout << BOLD << MAGENTA << "> MateriaSource crafts a new [" << type << "] from slot " << i << RESET << std::endl;
            return _memory[i]->clone();
        }
    }
    std::cout << BOLD << MAGENTA << "> MateriaSource does not know [" << type << "]" << RESET << std::endl;
    return 0; /* why can i do this*/
}