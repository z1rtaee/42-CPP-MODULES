#include "Zombie.hpp"

int main(void)
{
    std::cout << "\e[1;35m##### Testing zombieHorde function #####\e[0m" << std::endl;
    
    // Test 1: Create a horde of 5 zombies
    std::cout << "\n\e[1;33mTest 1: Creating horde of 5 zombies named 'Walker'\e[0m" << std::endl;
    int hordeSize = 5;
    Zombie* horde = zombieHorde(hordeSize, "Planta do Plants vs Zombies");
    
    if (horde)
    {
        std::cout << "\nCalling announce() for each zombie:" << std::endl;
        for (int i = 0; i < hordeSize; i++)
        {
            std::cout << "Zombie " << i + 1 << ": ";
            horde[i].announce();
        }
        
        std::cout << "\nDeleting the horde..." << std::endl;
        delete[] horde;
    }
    
    // Test 2: Create a horde of 3 zombies with different name
    std::cout << "\n\e[1;33mTest 2: Creating horde of 3 zombies named 'Crawler'\e[0m" << std::endl;
    hordeSize = 3;
    horde = zombieHorde(hordeSize, "Crawler do Plants vs Zombies");
    
    if (horde)
    {
        std::cout << "\nCalling announce() for each zombie:" << std::endl;
        for (int i = 0; i < hordeSize; i++)
        {
            std::cout << "Zombie " << i + 1 << ": ";
            horde[i].announce();
        }
        
        std::cout << "\nDeleting the horde..." << std::endl;
        delete[] horde;
    }
    
    // Test 3: Edge case - creating horde with 0 zombies
    std::cout << "\n\e[1;33mTest 3: \"Edge case\" - creating horde with 0 zombies\e[0m" << std::endl;
    horde = zombieHorde(0, "None");
    if (!horde)
    {
        std::cout << "Correctly returned NULL for 0 zombies" << std::endl;
    }
    
    // Test 4: Single zombie horde
    std::cout << "\n\e[1;33mTest 4: Creating horde of 1 zombie named 'Loner'\e[0m" << std::endl;
    horde = zombieHorde(1, "Loner");
    
    if (horde)
    {
        std::cout << "\nCalling announce() for the single zombie:" << std::endl;
        horde[0].announce();
        
        std::cout << "\nDeleting the single zombie..." << std::endl;
        delete[] horde;
    }
    
    std::cout << "\n\e[1;35m=== All tests completed ===\e[0m" << std::endl;
    
    return 0;
}