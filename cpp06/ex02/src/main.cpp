#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
    switch (rand() % 3) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            std::cerr << BOLD << "Error: " << RESET << "Random generator failed." << std::endl;
            return NULL;
    }
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Base * has been identified as...\n\t" << MAGENTA << "A" << RESET << " type!" << std::endl; 
    else if (dynamic_cast<B*>(p))
        std::cout << "Base * has been identified as...\n\t" << MAGENTA << "B" << RESET << " type!" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Base * has been identified as...\n\t" << MAGENTA << "C" << RESET << " type!" << std::endl;
    else
        std::cout << "Base * has been identified as...\n\t" << MAGENTA << "unknown" << RESET << " type?" << std::endl;
}

void identify(Base &p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Base & has been identified as...\n\t" << MAGENTA << "A" << RESET << " type!" << std::endl;
    } catch (const std::exception &e) {
        (void)e;
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "Base & has been identified as...\n\t" << MAGENTA << "B" << RESET << " type!" << std::endl;
        } catch (const std::exception &e) {
            (void)e;
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "Base & has been identified as...\n\t" << MAGENTA << "C" << RESET << " type!" << std::endl;
            } catch (const std::exception &e) {
                (void)e;
                std::cout << "Base & has been identified as...\n\t" << MAGENTA << "unknown" << RESET << " type?" << std::endl;
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    Base *object = generate();
    identify(object);
    identify(*object);
    delete object;
    return 0;
}
