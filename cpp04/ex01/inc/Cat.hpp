#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iomanip>
# include <iostream>

class Cat : public Animal {
    public:
        Cat();
        Cat(const Cat &src);
        ~Cat();
        
        Cat &operator=(const Cat &obj);

        void makeSound() const;
        Brain *getBrain() const;
    private:
        Brain *_brain;
};

#endif