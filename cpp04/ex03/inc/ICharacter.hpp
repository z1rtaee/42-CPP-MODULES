#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <iomanip>

/*colors :D*/
# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define BOLD "\e[1;37m"

class AMateria;

/*this class acts as an interface because it only contains virtual functions*/
/*every class that is a character should implement these operations*/
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