#include <iostream>
#include "Fixed.hpp"


/*//subject main
int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}

*/

//personal main
int main( void ){
    std::cout << "########## Simple Tests ##########" << std::endl;
    Fixed a;
    Fixed b(2.5f);
    Fixed c(256);
    
    std::cout << RESET << "Instance a: " << a << std::endl;
    std::cout << RESET << "Instance b: " << b << std::endl;
    std::cout << RESET << "Instance c: " << c << std::endl;
    
    //COPY ASSIGNMENT AND CONSTRUCTOR TEST
    std::cout << RESET << std::endl << "########## Copy Tests ##########" << std::endl;
    std::cout << BOLD << "copying the constructor with action: Fixed b_copy(b)" << std::endl; 
    Fixed b_copy(b);
    
    std::cout << RESET << "b = " << b << std::endl << "b_copy = " << b_copy << std::endl;
    b = b_copy;
    std::cout << RESET << "b = b_copy\nb = " << b << std::endl << "b_copy = " << b_copy << std::endl;

    //ARYTHMETIC OPERATORS TEST
    std::cout << RESET << std::endl << "########## ARYTHMETIC OPERATORS ##########" << std::endl;
    std::cout << std::endl << MAGENTA << "* MULTIPLIER *" << RESET << std::endl;
    std::cout << RESET << "a * b = " << a * b << std::endl;
    std::cout << RESET << "b * c = " << b * c << std::endl;
    std::cout << RESET << "a * c = " << a * b * c << std::endl;
    std::cout << std::endl << MAGENTA << "+ PLUS +" << RESET << std::endl;
    std::cout << RESET << "a + b = " << a + b << std::endl;
    std::cout << RESET << "b + c = " << b + c << std::endl;
    std::cout << RESET << "a + c = " << a + b + c << std::endl;
    std::cout << RESET << std::endl << MAGENTA << "- MINUS -" << RESET<< std::endl;
    std::cout << RESET << "a - b = " << a - b << std::endl;
    std::cout << RESET << "b - c = " << b - c << std::endl;
    std::cout << RESET << "a - c = " << a - b - c << std::endl;
    std::cout << std::endl << MAGENTA << "/ DIVISION /" << RESET << std::endl;
    std::cout << RESET << "a / b = " << a / b << std::endl;
    std::cout << RESET << "b / c = " << b / c << std::endl;
    std::cout << RESET << "a / c = " << a / b / c << std::endl;

    //INCREMENT/DECREMENT OPERATORS TEST
    std::cout << RESET << std::endl << "########## INCREMENT / DECREMENT OPERATORS ##########" << std::endl;
    Fixed counter;

    std::cout << std::endl << MAGENTA << "Initial value" << RESET << std::endl;
    std::cout << "counter = " << counter << " | raw = " << counter.getRawBits() << std::endl;
    std::cout << std::endl << MAGENTA << "-- PRE INCREMENT (++counter) --" << RESET << std::endl;
    std::cout << "result  = " << ++counter << " | raw = " << counter.getRawBits() << std::endl;
    std::cout << "counter = " << counter << " | raw = " << counter.getRawBits() << std::endl;
    std::cout << std::endl << MAGENTA << "-- POST INCREMENT (counter++) --" << RESET << std::endl;
    std::cout << "result  = " << counter++ << " | raw = " << counter.getRawBits() << std::endl;
    std::cout << "counter = " << counter << " | raw = " << counter.getRawBits() << std::endl;
    std::cout << std::endl << MAGENTA << "-- PRE DECREMENT (--counter) --" << RESET << std::endl;
    std::cout << "result  = " << --counter << " | raw = " << counter.getRawBits() << std::endl;
    std::cout << "counter = " << counter << " | raw = " << counter.getRawBits() << std::endl;
    std::cout << std::endl << MAGENTA << "-- POST DECREMENT (counter--) --" << RESET << std::endl;
    std::cout << "result  = " << counter-- << " | raw = " << counter.getRawBits() << std::endl;
    std::cout << "counter = " << counter << " | raw = " << counter.getRawBits() << std::endl;

    //COMPARISON OPERATORS TESTS
    std::cout << RESET << std::endl << "########## COMPARISON OPERATORS ##########" << std::endl;
    Fixed x(2.5f);
    Fixed y(2.5f);
    Fixed z(3.75f);

    std::cout << std::boolalpha;
    std::cout << "x = " << x << " | y = " << y << " | z = " << z << std::endl;
    std::cout << "x > z  : " << (x > z) << std::endl;
    std::cout << "x < z  : " << (x < z) << std::endl;
    std::cout << "x >= y : " << (x >= y) << std::endl;
    std::cout << "x <= y : " << (x <= y) << std::endl;
    std::cout << "x == y : " << (x == y) << std::endl;
    std::cout << "x != z : " << (x != z) << std::endl;
    std::cout << "x != y : " << (x != y) << std::endl;

    //MIN/MAX MEMBER FUNCTIONS TESTS
    std::cout << RESET << std::endl << "########## MIN / MAX FUNCTIONS ##########" << std::endl;
    Fixed m1(10.0f);
    Fixed m2(42.0f);
    const Fixed cm1(1.5f);
    const Fixed cm2(1.25f);
    Fixed &minRef = Fixed::min(m1, m2);

    minRef = Fixed(99.0f);
    std::cout << "non-const values -> m1 = " << m1 << " | m2 = " << m2 << std::endl;
    std::cout << "Fixed::min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
    std::cout << "Fixed::max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;
    std::cout << "after modifying min reference -> m1 = " << m1 << " | m2 = " << m2 << std::endl;
    std::cout << "const values -> cm1 = " << cm1 << " | cm2 = " << cm2 << std::endl;
    std::cout << "Fixed::min(cm1, cm2) = " << Fixed::min(cm1, cm2) << std::endl;
    std::cout << "Fixed::max(cm1, cm2) = " << Fixed::max(cm1, cm2) << std::endl;

    return 0;
}