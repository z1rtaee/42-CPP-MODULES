#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {
    public:
        Point(void); /*default constructor*/
        Point(const Point &src); /*copy constructor :c*/
        Point(const float x, const float y); /*constructor to initialize coordinates :D*/
        Point& operator=(const Point &src); /*copy assignment :D*/
        ~Point(void); /*destructor >:c*/
        Fixed getX(void) const;
        Fixed getY(void) const;
    private:
        const Fixed _x;
        const Fixed _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif