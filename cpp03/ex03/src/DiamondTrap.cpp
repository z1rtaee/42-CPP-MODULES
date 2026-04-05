#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Gustave_clap_name") ,FragTrap(), ScavTrap(), _name("Gustave"){
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "DiamondTrap Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    FragTrap    frag;
    ScavTrap    scav;
    this->_hitPoints = frag.getHitPoints();
    this->_energyPoints = scav.getEnergyPoints();
    this->_attackDamage = frag.getAttackDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), FragTrap(src), ScavTrap(src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "DiamondTrap copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    *this = src;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"DiamondTrap name constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    FragTrap    frag;
    ScavTrap    scav;
    this->_hitPoints = frag.getHitPoints();
    this->_energyPoints = scav.getEnergyPoints();
    this->_attackDamage = frag.getAttackDamage();
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj) { 
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"DiamondTrap copy assignment called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &obj) {
        ClapTrap::operator=(obj);
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"DiamondTrap destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;

}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::WhoAmI() {
    std::cout << RESET << "Who am I? Very good question ദ്ദി(˵ •̀ ᴗ - ˵ ) ✧ " << std::endl << "I am " 
            << this->_name << " and my ClapTrap dad is " << MAGENTA << ClapTrap::_name << RESET << "!!" << std::endl; 
}
