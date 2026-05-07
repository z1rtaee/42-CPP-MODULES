#include "whatever.hpp"

/*subject main
int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}
*/

/*my main*/

struct Score {
    int value;

    Score(int input = 0) : value(input) {}

    bool operator<(const Score &other) const {
        return (value < other.value);
    }

    bool operator>(const Score &other) const {
        return (value > other.value);
    }
};

std::ostream &operator<<(std::ostream &o, const Score &score) {
    o << score.value;
    return (o);
}

int main(void) {
    std::cout << "######### TEMPLATE TESTS (ex00) #########" << std::endl;

    std::cout << "\n[Phase 1] int swap / min / max" << std::endl;
    int a = 2;
    int b = 3;
    std::cout << "Before swap -> a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After  swap -> a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::cout << "\n[Phase 2] std::string swap / min / max" << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "Before swap -> c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After  swap -> c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    std::cout << "\n[Phase 3] char and float checks" << std::endl;
    char x = 'z';
    char y = 'a';
    std::cout << "min('" << x << "', '" << y << "') = " << ::min(x, y) << std::endl;
    std::cout << "max('" << x << "', '" << y << "') = " << ::max(x, y) << std::endl;

    float f1 = 42.42f;
    float f2 = 42.43f;
    std::cout << "min(" << f1 << ", " << f2 << ") = " << ::min(f1, f2) << std::endl;
    std::cout << "max(" << f1 << ", " << f2 << ") = " << ::max(f1, f2) << std::endl;

    std::cout << "\n[Phase 4] equal values behavior" << std::endl;
    int sameA = 10;
    int sameB = 10;
    std::cout << "min(10, 10) = " << ::min(sameA, sameB) << std::endl;
    std::cout << "max(10, 10) = " << ::max(sameA, sameB) << std::endl;

    std::cout << "\n[Phase 5] custom type with operators" << std::endl;
    Score s1(17);
    Score s2(99);
    std::cout << "Before swap -> s1 = " << s1 << ", s2 = " << s2 << std::endl;
    ::swap(s1, s2);
    std::cout << "After  swap -> s1 = " << s1 << ", s2 = " << s2 << std::endl;
    std::cout << "min(s1, s2) = " << ::min(s1, s2) << std::endl;
    std::cout << "max(s1, s2) = " << ::max(s1, s2) << std::endl;

    std::cout << "\n========== END OF TESTS ==========" << std::endl;
    return (0);
}
