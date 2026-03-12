#include "Weapon.hpp"

Weapon::Weapon(void) : _type("")
{
}

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon(void)
{
}

std::string const &Weapon::getType()
{
    return _type;
}

void Weapon::setType(std::string const type)
{
    _type = type;
}