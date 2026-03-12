#include "Zombie.hpp"

int main()
{
    std::cout << "\e[0;37m##### Creating zombie on the heap #####\e[0;37m" << std::endl;
    Zombie* heapZombie = newZombie("\e[1;37mHeapZombie\e[1;37m");
    heapZombie->announce();
    delete heapZombie; // Must manually delete heap-allocated zombie
    
    std::cout << "\n\e[0;37m##### Creating zombie on the stack #####\e[0;37m" << std::endl;
    randomChump("\e[1;37mStackZombie\e[1;37m"); // Zombie is automatically destroyed when function ends aka scope ends
    
    std::cout << "\n\e[0;37m=== Testing multiple heap zombies ===\e[0;37m" << std::endl;
    Zombie* zombie1 = newZombie("\e[1;37mAntonio\e[1;37m");
    Zombie* zombie2 = newZombie("\e[1;37mGeraldo\e[1;37m");
    
    zombie1->announce();
    zombie2->announce();
    
    delete zombie1; // Manual cleanup required #free
    delete zombie2;
    
    std::cout << "\n\e[0;37m=== Testing multiple stack zombies ===\e[0;37m" << std::endl;
    randomChump("\e[1;37mAmerico\e[1;37m");
    randomChump("\e[1;37mRobertina\e[1;37m");
    
    return 0;
}
