#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

/*colors :D*/
# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define BOLD "\e[1;37m"


class Character : public ICharacter {
    public:
        Character();
        Character(const Character &src);
        Character(const std::string &name);
        ~Character();

        Character &operator=(const Character &obj);
        std::string const &getName() const;

        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
    private:
        struct _FloorNode {
            AMateria *materia;
            _FloorNode *next;
        };

        std::string _name;
        AMateria *_inventory[4];
        _FloorNode *_floor;

        void clearInventory();
        void clearFloor();
        void copyFrom(const Character &src);
        
};

#endif