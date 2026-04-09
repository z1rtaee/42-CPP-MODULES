#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <iomanip>

/*colors :D*/
# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define BOLD "\e[1;37m"

class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &src);
        WrongAnimal &operator=(const WrongAnimal &obj);
        ~WrongAnimal();

        void makeSound() const;
        std::string getType() const;
    
    protected:
        std::string _type;
};

#endif