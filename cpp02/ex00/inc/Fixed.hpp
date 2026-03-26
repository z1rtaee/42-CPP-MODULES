#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define BOLD "\e[1;37m"

class Fixed {
    public:
        Fixed(void); //default constructor declaration
        Fixed(const Fixed &src); //copy constructor declaration - why is this object the one being passed
        Fixed& operator=(const Fixed &src);
        ~Fixed(void);

        int getRawBits(void) const; //it cannot modify the object, so it is a const function (this)
        void setRawBits(int const raw);
        
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

#endif