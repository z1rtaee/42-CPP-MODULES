#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Gustave"), _floor(NULL) {
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
}

Character::Character(const Character &src) : _name(src._name), _floor(NULL) {
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
    copyFrom(src);
}

Character::Character(const std::string &name) : _name(name), _floor(NULL) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Character Name constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
}

Character::~Character() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Character Default destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    clearInventory();
    clearFloor();
}

Character &Character::operator=(const Character &obj) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Character Copy assignment called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this == &obj) {
        return *this;
    }

    clearInventory();
    clearFloor();
    this->_name = obj._name;
    copyFrom(obj);
    return *this;
}

std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria *m) {
    if (!m) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!this->_inventory[i]) {
            this->_inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) {
        return;
    }
    if (!this->_inventory[idx]) {
        return;
    }

    _FloorNode *node = new _FloorNode;
    node->materia = this->_inventory[idx];
    node->next = _floor;
    _floor = node;
    this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx > 3) {
        return;
    }
    if (this->_inventory[idx]) {
        this->_inventory[idx]->use(target);
    }
}

void Character::clearInventory() {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i]) {
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    }
}

void Character::clearFloor() {
    _FloorNode *curr = _floor;
    while (curr) {
        _FloorNode *next = curr->next;
        delete curr->materia;
        delete curr;
        curr = next;
    }
    _floor = NULL;
}

void Character::copyFrom(const Character &src) {
    for (int i = 0; i < 4; i++) {
        if (src._inventory[i]) {
            this->_inventory[i] = src._inventory[i]->clone();
        } else {
            this->_inventory[i] = NULL;
        }
    }
}
