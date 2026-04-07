#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iomanip>
# include <iostream>

class Dog : public Animal {
    public:
        Dog();
        Dog(const Dog &src);
        ~Dog();
        
        Dog &operator=(const Dog &obj);

        void makeSound() const;
};

#endif