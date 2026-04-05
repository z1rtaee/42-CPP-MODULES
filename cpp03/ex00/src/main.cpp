#include "ClapTrap.hpp"

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
    ClapTrap b("Maelle");
    ClapTrap c(b);
    ClapTrap d;
    d = b;

    std::cout << RESET << "\nCurrent status:" << std::endl;
    print_status(a);
    print_status(b);
    print_status(c);
    print_status(d);

    std::cout << RESET << "\nAction tests:" << std::endl;
    b.attack("Target Dummy");
    b.takeDamage(3);
    b.beRepaired(2);
    print_status(b);

    std::cout << RESET << "\nDeath + edge cases:" << std::endl;
    b.takeDamage(50);
    b.attack("Target Dummy");
    b.beRepaired(5);
    print_status(b);

    std::cout << MAGENTA << "\n######### END OF TESTS ##########" << RESET << std::endl;
    return (0);
}