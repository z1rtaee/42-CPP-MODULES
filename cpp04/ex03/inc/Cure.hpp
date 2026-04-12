#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

/*colors :D*/
# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define BOLD "\e[1;37m"

class Cure : public AMateria {
    public:  
        Cure();
        Cure(const Cure &src);
        virtual ~Cure();
    
        Cure &operator=(const Cure &obj);
    
        void use(ICharacter& target);
        AMateria* clone() const;
} ;

#endif