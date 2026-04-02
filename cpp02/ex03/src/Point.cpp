#include "Point.hpp"

/*Constructors/Desturctors*/

Point::Point(void) : _x(0), _y(0){
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Point Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Point::Point(const Point &src) : _x(src._x), _y(src._y){
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Point Copy constructor called" << MAGENTA " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Point Float constructor called" << MAGENTA " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Point::~Point(void) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD "Point Destructor called" << " ദ്ദി(˵ •̀ ᴗ - ˵ ) ✧" << RESET << std::endl;
}

Point &Point::operator=(const Point &src){
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Point Copy assignment operator called" << MAGENTA " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    (void)src;
    return *this;
}

Fixed Point::getX(void) const {
    return this->_x;
}

Fixed Point::getY(void) const {
    return this->_y;
}
