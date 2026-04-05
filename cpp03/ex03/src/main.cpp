#include "DiamondTrap.hpp"

void    print_status(const ClapTrap &obj) {
	std::cout << RESET << "##########" << MAGENTA << "STATUS" << RESET << "##########" << std::endl;
	std::cout << BOLD << "|" << " Name         " << "|" << " " << obj.getName() << "  |" << std::endl;
	std::cout << BOLD << "|" << " HitPoints    " << "|" << " " << obj.getHitPoints() << "       |" << std::endl;
	std::cout << BOLD << "|" << " EnergyPoints " << "|" << " " << obj.getEnergyPoints() << "       |" << std::endl;
	std::cout << BOLD << "|" << " AttackDamage " << "|" << " " << obj.getAttackDamage() << "       |" << std::endl;
}

int main() {
	std::cout << MAGENTA << "######### DIAMOND TRAP TESTS ##########" << std::endl;

	DiamondTrap a;
	DiamondTrap b("Maelle");
	DiamondTrap c(b);
	DiamondTrap d;
	d = b;

	std::cout << RESET << "\nCurrent status:" << std::endl;
	print_status(a);
	print_status(b);
	print_status(c);
	print_status(d);

	std::cout << RESET << "\nAction tests:" << std::endl;
	b.attack("Target Burrinha");
	b.takeDamage(20);
	b.beRepaired(10);
	b.guardGate();
	b.highFivesGuys();
	print_status(b);

	std::cout << MAGENTA << "\n######### END OF TESTS ##########" << RESET << std::endl;
	return (0);
}
