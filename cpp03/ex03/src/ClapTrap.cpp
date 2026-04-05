#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Gustave"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "ClapTrap Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "ClapTrap copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"ClapTrap destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &obj) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"ClapTrap copy assignment called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &obj) { 
        this->_name = obj._name;
        this->_hitPoints = obj._hitPoints;
        this->_energyPoints = obj._energyPoints;
        this->_attackDamage = obj._attackDamage;
    }
    return *this;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"ClapTrap name constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

std::string const &ClapTrap::getName(void) const {
    return (this->_name);
}

unsigned int const &ClapTrap::getHitPoints(void) const {
    return (this->_hitPoints);
}

unsigned int const &ClapTrap::getEnergyPoints(void) const {
    return (this->_energyPoints);
}

unsigned int const &ClapTrap::getAttackDamage(void) const {
    return (this->_attackDamage);
}

void    ClapTrap::attack(const std::string &target) {
    if (!this->getHitPoints()) {
        std::cout << MAGENTA << "ERROR:" << RESET << " ClapTrap " << this->getName() << " is dead it cannot attack!" << std::endl;
        return ;
    }
    if (!this->getEnergyPoints()) {
        std::cout << MAGENTA << "ERROR:" << RESET << " ClapTrap " << this->getName() << " is out of energy it cannot attack!" << std::endl;
        return ;
    }
    std::cout << RESET << "ClapTrap " << this->getName() << MAGENTA << " attacks " << RESET << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (!this->getHitPoints()) {
        std::cout << MAGENTA << "ERROR:" << RESET << " ClapTrap " << this->getName() << " is already dead!" << std::endl;
    }
    else {
        if (this->getHitPoints() <= amount) {
            this->_hitPoints = 0;
            std::cout << RESET << "ClapTrap " << this->getName() << " was crashed to death!" << MAGENTA << "\nWell Played !!" << RESET << std::endl;
        }
        else {
            std::cout << RESET << "ClapTrap " << this->getName() << " just took " << amount << " points of damage!\nCurrent Health: " << this->getHitPoints() << "hp!" << std::endl;
            this->_hitPoints -= amount;
        }
    }
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (!this->getHitPoints()) {
        std::cout << MAGENTA << "ERROR:" << RESET << " ClapTrap " << this->getName() << " is dead it cannot repair itself!" << std::endl;
        return ;
    }
    if (!this->getEnergyPoints()) {
        std::cout << MAGENTA << "ERROR:" << RESET << " ClapTrap " << this->getName() << " is out of energy it cannot repair itself!" << std::endl;
        return ;
    }
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << RESET << "ClapTrap " << this->getName() << " repairs itself for a total of " << amount << " hitPoints!"
                << " !!\nCurrent Health: " << this->getHitPoints() << "hp" << std::endl;
}
