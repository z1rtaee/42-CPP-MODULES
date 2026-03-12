#include "HumanB.hpp"

HumanB::HumanB() : _name("Unknown"), _weapon(NULL)
{
}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if (_weapon == NULL)
        std::cout << _name << " has no weapon to attack with!" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon;
}