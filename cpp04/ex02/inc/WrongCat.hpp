#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iomanip>
# include <iostream>

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(const WrongCat &src);
        ~WrongCat();
        
        WrongCat &operator=(const WrongCat &obj);

        void makeSound() const;
};


#endif