#include "Fixed.hpp"

/*Constructors/Destructor :D*/

Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Fixed Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Fixed Copy constructor called" << MAGENTA " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    *this = src; //we can use the copy assignment operator to copy the value of the other object to this object
}

Fixed::Fixed(const int val){
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"Fixed Int constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET <<std::endl;
    _fixedPointValue = val << _fractionalBits;
}

Fixed::Fixed(const float val){
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD <<"Fixed Float constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    _fixedPointValue = roundf(val * (1 << _fractionalBits));
}

Fixed::~Fixed(void) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD "Fixed Destructor called" << " ദ്ദി(˵ •̀ ᴗ - ˵ ) ✧" << RESET << std::endl;
}

/*Overloading Operators*/

Fixed &Fixed::operator=(const Fixed &src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Fixed Copy assignment operator called" << MAGENTA " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &src)//we need to check if the other object is not the same as this object to avoid self-assignment
        this->_fixedPointValue = src.getRawBits(); //get the value of the other obj
    return *this; //we need to return this obj to allow chaining of assignment operators
}

std::ostream& operator<<(std::ostream &out, const Fixed &src){
    out << src.toFloat();
    return out;
}

/*Arithmetic Operators*/

Fixed Fixed::operator+(const Fixed &src) const{
    Fixed result;
    result.setRawBits(this->_fixedPointValue + src._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &src) const{
    Fixed result;
    result.setRawBits((this->_fixedPointValue * src._fixedPointValue) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &src) const{
    if (src.getRawBits() == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    Fixed result;
    result.setRawBits((this->_fixedPointValue << _fractionalBits) / src._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &src) const{
    Fixed result;
    result.setRawBits(this->_fixedPointValue - src._fixedPointValue);
    return result;
}

/*Comparison Operators*/
bool Fixed::operator>(const Fixed &src) const {
    return this->getRawBits() > src.getRawBits();
}

bool Fixed::operator<(const Fixed &src) const {
    return this->getRawBits() < src.getRawBits();
}

bool Fixed::operator>=(const Fixed &src) const {
    return this->getRawBits() >= src.getRawBits();
}

bool Fixed::operator<=(const Fixed &src) const {
    return this->getRawBits() <= src.getRawBits();
}

bool Fixed::operator==(const Fixed &src) const {
    return this->getRawBits() == src.getRawBits();
}

bool Fixed::operator!=(const Fixed &src) const {
    return this->getRawBits() != src.getRawBits();
}

/*Increment/Decrement Operators*/
Fixed& Fixed::operator++(void) {
    this->_fixedPointValue++;
    return *this;
}

Fixed& Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

 

/*Member Functions*/

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return a;
    return b;

}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    return b;
}


float Fixed::toFloat(void) const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

/*Getter/Setter*/

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}
