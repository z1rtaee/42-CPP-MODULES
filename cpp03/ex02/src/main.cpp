#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void    print_status(const ClapTrap &obj) {
    std::cout << RESET << "##########" << MAGENTA << "STATUS" << RESET << "##########" << std::endl;
    std::cout << BOLD << "|" << " Name         " << "|" << " " << obj.getName() << "  |" <<std::endl;
    std::cout << BOLD << "|" << " HitPoints    " << "|" << " " << obj.getHitPoints() << "       |" <<std::endl;
    std::cout << BOLD << "|" << " EnergyPoints " << "|" << " " << obj.getEnergyPoints() << "       |" <<std::endl;
    std::cout << BOLD << "|" << " AttackDamage " << "|" << " " << obj.getAttackDamage() << "       |" <<std::endl;
}

int main() {
    std::cout << MAGENTA << "######### CLAP TRAP TESTS ##########" << std::endl;
    
    ClapTrap a;
    ScavTrap b("Maelle");
    ClapTrap c(b);
    ClapTrap d;
    ScavTrap e(b);
    FragTrap f("Alisia");
    d = b;

    std::cout << RESET << "\nCurrent status:" << std::endl;
    print_status(a);
    print_status(b);
    print_status(c);
    print_status(d);
    print_status(e);
    print_status(f);

    std::cout << RESET << "\nAction tests:" << std::endl;
    b.attack("Target Burrinha");
    b.takeDamage(3);
    b.beRepaired(2);
    a.attack(b.getName());
    a.takeDamage(10);
    a.beRepaired(2);
    f.attack(a.getName());
    print_status(b);
    print_status(a);
    print_status(f);

    std::cout << RESET << "\nDeath + edge cases:" << std::endl;
    b.takeDamage(50);
    b.attack("Target Burrinha");
    b.beRepaired(5);
    print_status(b);

    std::cout << MAGENTA << "\n######### END OF TESTS ##########" << RESET << std::endl;
    return (0);
}
