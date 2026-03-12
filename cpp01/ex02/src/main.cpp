#include <iostream>
#include <string>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string string2 = "Nova string";
    std::string *stringPTR = &string; //pontos fazer "swaps "
    std::string &stringREF = string; //alias? nao podes fazer swaps é so um alias (alocar uma referencia)
    //nao e modifiable 
    //&stringREF = string2;
    std::cout << "\e[1;35m##### Memory Addresses #####\e[0m" << std::endl;
    std::cout << "Memory address of the string variable:   " << &string << std::endl;
    std::cout << "Memory address held by stringPTR:        " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF:        " << &stringREF << std::endl;
    
    std::cout << "\n\e[1;35m##### Values #####\e[0m" << std::endl;
    std::cout << "Value of the string variable:           " << string << std::endl;
    std::cout << "Value pointed to by stringPTR:          " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF:          " << stringREF << std::endl;
    
    std::cout << "\n\e[1;35m##### Observations #####\e[0m" << std::endl;
    std::cout << "• All three memory addresses are identical!" << std::endl;
    std::cout << "• All three values are identical!" << std::endl;
    std::cout << "• References are just another syntax for address manipulation ;P!" << std::endl;
    
    return 0;
}
