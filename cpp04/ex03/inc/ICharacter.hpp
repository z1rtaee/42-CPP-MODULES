#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <iomanip>
# include "AMateria.hpp"

/*this class acts as an interface because it only contains virtual functions*/
class ICharacter
{
    public:
        virtual ~ICharacter() {}
    
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
}; 

#endif