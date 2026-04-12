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
            delete _memory[i];
            _memory[i] = NULL;
        }
    }
}

void    MateriaSource::learnMateria(AMateria *obj) {
    if (!obj) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!_memory[i]) {
            _memory[i] = obj->clone();
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_memory[i] && _memory[i]->getType() == type) {
            return _memory[i]->clone();
        }
    }
    return 0; /* why can i do this*/
}