#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "FragTrap Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "FragTrap copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    *this = src;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"FragTrap name constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap &FragTrap::operator=(const FragTrap &obj) { 
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"FragTrap copy assignment called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &obj) {
        ClapTrap::operator=(obj);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"FragTrap destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;

}

void FragTrap::attack(const std::string &target) {
    if (!this->getHitPoints()) {
        std::cout << MAGENTA << "ERROR:" << RESET << " FragTrap " << this->getName() << " is dead it cannot attack!" << std::endl;
        return ;
    }
    if (!this->getEnergyPoints()) {
        std::cout << MAGENTA << "ERROR:" << RESET << " FragTrap " << this->getName() << " is out of energy it cannot attack!" << std::endl;
        return ;
    }
    std::cout << RESET << "FragTrap " << this->getName() << MAGENTA << " attacks " << RESET << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void    FragTrap::highFivesGuys(void) {
    std::cout << RESET << "FragTrap " << this->getName() << " requests a positive "<< MAGENTA << "high Five" << RESET << "!" << std::endl;
}