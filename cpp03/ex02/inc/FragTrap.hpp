#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap(void);
        FragTrap(const FragTrap &src);
        FragTrap(const std::string name);
        ~FragTrap();

        FragTrap    &operator=(const FragTrap &obj);

        void    attack(const std::string &target);
        void    highFivesGuys(void);
};


#endif