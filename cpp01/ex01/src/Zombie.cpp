#include "Zombie.hpp"

Zombie::Zombie(void) : _name("Unknown")
{
}

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie(void)
{
    std::cout << _name << ": \e[0;31mDestroyed\e[0m" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << _name << ": \e[0;32mBraiiiiiiinnnzzzZ...\e[0m" << std::endl;
}

void Zombie::setName(std::string name)
{
    _name = name;
}