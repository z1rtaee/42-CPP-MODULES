#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Copy constructor called" << MAGENTA " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    *this = src; //we can use the copy assignment operator to copy the value of the other object to this object
}

Fixed &Fixed::operator=(const Fixed &src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Copy assignment operator called" << MAGENTA " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &src)//we need to check if the other object is not the same as this object to avoid self-assignment
        this->_fixedPointValue = src.getRawBits(); //get the value of the other obj
    return *this; //we need to return this obj to allow chaining of assignment operators
}

Fixed::~Fixed(void) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD "Destructor called" << " ദ്ദി(˵ •̀ ᴗ - ˵ ) ✧" << RESET << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "getRawBits member function called" << MAGENTA << " ᗜ⩊ᗜ" << RESET << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "setRawBits member function called" << MAGENTA <<" ᗜ⩊ᗜ" << RESET << std::endl;
    this->_fixedPointValue = raw;
}


