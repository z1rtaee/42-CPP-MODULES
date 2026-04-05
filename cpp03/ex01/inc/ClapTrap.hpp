#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <iomanip>

/*colors :D*/
# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define BOLD "\e[1;37m"

class ClapTrap {
    public:
        /*Default construct/destruct*/
        ClapTrap(void);
        ClapTrap(const ClapTrap &src);
        ClapTrap(const std::string name);
        ClapTrap &operator=(const ClapTrap &obj);
        ~ClapTrap();

        
        /*mandatory member functions*/
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        /*getters :D*/
        std::string const &getName(void) const;
        unsigned int const &getHitPoints(void) const;
        unsigned int const &getEnergyPoints(void) const;
        unsigned int const &getAttackDamage(void) const;

    protected: //accessor to let the criançinhas also get these attributes
        std::string     _name;
        unsigned int    _hitPoints;
        unsigned int    _energyPoints;
        unsigned int    _attackDamage;
};

#endif