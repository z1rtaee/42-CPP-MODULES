#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iomanip>
# include <iostream>

class Dog : public AAnimal {
    public:
        Dog();
        Dog(const Dog &src);
        ~Dog();
        
        Dog &operator=(const Dog &obj);

        void makeSound() const;
        Brain *getBrain() const;
    private:
        Brain *_brain;
};

#endif
























