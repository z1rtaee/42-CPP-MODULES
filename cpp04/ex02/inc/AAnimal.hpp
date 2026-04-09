#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <iomanip>

/*colors :D*/
# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define BOLD "\e[1;37m"

class AAnimal {
    public:
        AAnimal();
        AAnimal(const AAnimal &src);
        AAnimal &operator=(const AAnimal &obj);
        virtual ~AAnimal();

        virtual void makeSound() const = 0;
        std::string getType() const;
    
    protected:
        std::string _type;
};

#endif