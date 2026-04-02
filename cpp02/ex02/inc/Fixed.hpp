#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <math.h>

# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define BOLD "\e[1;37m"

class Fixed {
    public:
        /*constructors/Destructor :D*/
        Fixed(void); 
        Fixed(const Fixed &src); //copy constructor declaration - why is this object the one being passed
        Fixed(const int val);
        Fixed(const float val);
        ~Fixed(void);

        /*Overloading Operators*/
        Fixed& operator=(const Fixed &src);
        /*Arithmetic Operators*/
        Fixed operator+(const Fixed &src) const;
        Fixed operator-(const Fixed &src) const;
        Fixed operator*(const Fixed &src) const;
        Fixed operator/(const Fixed &src) const;
        /*Increment/Decrement Operators*/
        Fixed& operator++(void);
        Fixed& operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);
        /*Comparison Operators*/
        bool operator>(const Fixed &src) const;
        bool operator<(const Fixed &src) const;
        bool operator>=(const Fixed &src) const;
        bool operator<=(const Fixed &src) const;
        bool operator==(const Fixed &src) const;
        bool operator!=(const Fixed &src) const;

        /*Overloaded Member Functions*/
        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);

        /*Getters/Setters*/
        int getRawBits(void) const; //it cannot modify the object, so it is a const function (this)
        void setRawBits(int const raw);
        
        /*others*/
        int toInt(void) const;
        float toFloat(void) const;
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &src);

#endif