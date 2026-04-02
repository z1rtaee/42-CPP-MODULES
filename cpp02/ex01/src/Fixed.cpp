#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Copy constructor called" << MAGENTA " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    *this = src; //we can use the copy assignment operator to copy the value of the other object to this object
}

Fixed::Fixed(const int val){
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"Int constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << std::endl;
    _fixedPointValue = val << _fractionalBits;
}

Fixed::Fixed(const float val){
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"Float constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << std::endl;
    _fixedPointValue = roundf(val * (1 << _fractionalBits));
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

float Fixed::toFloat(void) const { //porque dar cast para float aka pesquisar casts in c++
    return (float)_fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

std::ostream& operator<<(std::ostream &out, const Fixed &src)
{
    out << src.toFloat();
    return out;
}
