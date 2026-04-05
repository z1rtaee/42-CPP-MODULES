#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap(void);
        ScavTrap(const ScavTrap &src);
        ScavTrap(const std::string name);
        ~ScavTrap();

        ScavTrap    &operator=(const ScavTrap &obj);

        void    attack(const std::string &target);
        void    guardGate(void);
};

#endif