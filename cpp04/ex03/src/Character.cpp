#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Gustave"), _floor(NULL) {
    std::cout << MAGENTA << ".* " << BOLD << "Character default constructor called for [" << _name << "]" << RESET << std::endl;
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
}

Character::Character(const Character &src) : _name(src._name), _floor(NULL) {
    std::cout << MAGENTA << ".* " << BOLD << "Character copy constructor called for [" << _name << "]" << RESET << std::endl;
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
    copyFrom(src);
}

Character::Character(const std::string &name) : _name(name), _floor(NULL) {
    std::cout << MAGENTA << ".* " << BOLD << "Character named constructor called for [" << _name << "]" << RESET << std::endl;
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
    }
}

Character::~Character() {
    std::cout << MAGENTA << ".* " << BOLD << "Character destructor called for [" << _name << "]" << RESET << std::endl;
    clearInventory();
    clearFloor();
}

Character &Character::operator=(const Character &obj) {
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
        std::cout << BOLD << MAGENTA << "> " << _name << " tries to equip nothing. Turn wasted." << RESET << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!this->_inventory[i]) {
            this->_inventory[i] = m;
            std::cout << BOLD << MAGENTA << "> " << _name << " equips [" << m->getType() << "] in slot " << i << RESET << std::endl;
            return;
        }
    }
    std::cout << BOLD << MAGENTA << "> " << _name << " cannot equip [" << m->getType() << "]: inventory full" << RESET << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) {
        std::cout << BOLD << MAGENTA << "> " << _name << " cannot unequip slot " << idx << ": invalid slot" << RESET << std::endl;
        return;
    }
    if (!this->_inventory[idx]) {
        std::cout << BOLD << MAGENTA << "> " << _name << " has no materia in slot " << idx << RESET << std::endl;
        return;
    }

    _FloorNode *node = new _FloorNode;
    node->materia = this->_inventory[idx];
    node->next = _floor;
    _floor = node;
    std::cout << BOLD << MAGENTA << "> " << _name << " drops [" << this->_inventory[idx]->getType() << "] from slot " << idx << RESET << std::endl;
    this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx > 3) {
        std::cout << BOLD << MAGENTA << "> " << _name << " cannot use slot " << idx << ": invalid slot" << RESET << std::endl;
        return;
    }
    if (this->_inventory[idx]) {
        std::cout << BOLD << MAGENTA << "> " << _name << " uses [" << this->_inventory[idx]->getType() << "] on " << target.getName() << RESET << std::endl;
        this->_inventory[idx]->use(target);
        return;
    }
    std::cout << BOLD << MAGENTA << "> " << _name << " tries to cast from empty slot " << idx << RESET << std::endl;
}

void Character::clearInventory() {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i]) {
            std::cout << MAGENTA << ".* " << BOLD << "Deleting inventory slot " << i << " for [" << _name << "]" << RESET << std::endl;
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    }
}

void Character::clearFloor() {
    _FloorNode *curr = _floor;
    while (curr) {
        _FloorNode *next = curr->next;
        std::cout << MAGENTA << ".* " << BOLD << "Cleaning dropped materia [" << curr->materia->getType() << "] for [" << _name << "]" << RESET << std::endl;
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
            std::cout << MAGENTA << ".* " << BOLD << "Copied slot " << i << " with [" << this->_inventory[i]->getType() << "]" << RESET << std::endl;
        } else {
            this->_inventory[i] = NULL;
        }
    }
}
