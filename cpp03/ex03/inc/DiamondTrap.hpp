#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    public:
        DiamondTrap(void);
        DiamondTrap(const DiamondTrap &src);
        DiamondTrap(std::string name);
        ~DiamondTrap();

        DiamondTrap &operator=(const DiamondTrap &obj);

        void attack(const std::string &target);
        void WhoAmI();
        
    private:
        std::string _name;
} ;

#endif