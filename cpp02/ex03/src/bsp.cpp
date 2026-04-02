#include "Point.hpp"

/*get signed area :P*/
static Fixed area(Point const a, Point const b, Point const c) {
    return ((b.getX() - a.getX()) * (c.getY() - a.getY()) -
            (b.getY() - a.getY()) * (c.getX() - a.getX()));
}

bool    bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed A1 = area(point, a, b);
    Fixed A2 = area(point, b, c);
    Fixed A3 = area(point, c, a);

    if (A1 == 0 || A2 == 0 || A3 == 0)
        return false;
    bool has_neg = (A1 < 0 || A2 < 0 || A3 < 0);
    bool has_pos = (A1 > 0 || A2 > 0 || A3 > 0);
    return !(has_neg && has_pos);
}
