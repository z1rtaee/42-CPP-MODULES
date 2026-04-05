#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "ScavTrap Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "ScavTrap copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    *this = src;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"ScavTrap name constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj) { 
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"ScavTrap copy assignment called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &obj) {
        ClapTrap::operator=(obj);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"ScavTrap destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;

}

void ScavTrap::attack(const std::string &target) {
    if (!this->getHitPoints()) {
        std::cout << MAGENTA << "ERROR:" << RESET << " ScavTrap " << this->getName() << " is dead it cannot attack!" << std::endl;
        return ;
    }
    if (!this->getEnergyPoints()) {
        std::cout << MAGENTA << "ERROR:" << RESET << " ScavTrap " << this->getName() << " is out of energy it cannot attack!" << std::endl;
        return ;
    }
    std::cout << RESET << "ScavTrap " << this->getName() << MAGENTA << " attacks " << RESET << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void    ScavTrap::guardGate(void) {
    std::cout << RESET << "ScavTrap " << this->getName() << " is now in "<< MAGENTA << "Gate Keeper Mode" << RESET << "." << std::endl;
}