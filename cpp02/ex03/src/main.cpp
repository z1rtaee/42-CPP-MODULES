#include "Point.hpp"

int main(void)
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point inside(2, 2);
    Point outside(10, 10);
    Point edge(5, 0);
    Point vertex(0, 0);

    std::cout << b.getX() << std::endl;
    std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "Edge: " << bsp(a, b, c, edge) << std::endl;
    std::cout << "Vertex: " << bsp(a, b, c, vertex) << std::endl;
}
