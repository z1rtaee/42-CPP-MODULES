#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <iomanip>
# include "ICharacter.hpp"

class AMateria {
    protected:
        std::string _type;

    public:
        AMateria();
        AMateria(const AMateria &src);
        AMateria(std::string const & type);
        virtual ~AMateria();

        AMateria &operator=(const AMateria &obj);
        
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        
        std::string const & getType() const; //Returns the materia type
} ;

#endif