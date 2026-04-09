#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <iomanip>

/*colors :D*/
# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define BOLD "\e[1;37m"

class Animal {
    public:
        Animal();
        Animal(const Animal &src);
        Animal &operator=(const Animal &obj);
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getType() const;
    
    protected:
        std::string _type;
};

#endif