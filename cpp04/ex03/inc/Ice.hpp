#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

/*colors :D*/
# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define BOLD "\e[1;37m"

class Ice : public AMateria {
    public:
        Ice();
        Ice(const Ice &src);
        virtual ~Ice();
    
        Ice &operator=(const Ice &obj);
    
        void use(ICharacter& target);
        AMateria* clone() const;
} ; 

#endif