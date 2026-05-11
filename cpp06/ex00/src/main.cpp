#include "ScalarConverter.hpp"
/*
static std::string getTypeName(scalarType type)
{
	if (type == CHAR)
    return "CHAR";
	else if (type == INT)
    return "INT";
	else if (type == FLOAT)
    return "FLOAT";
	else if (type == DOUBLE)
    return "DOUBLE";
	return "INV";
}
*/

int main(int argc, char **argv)
{
    std::cout << "============ "<< BOLD << MAGENTA << "SCALAR TYPES CONVERTER " << RESET << "============" << std::endl;
	if (argc != 2)
	{
        std::cerr << "Error: Scalar Converter Program needs exactly one argument as input!" << std::endl;
		std::cerr << "Usage: ./ScalarConverter <literal>" << std::endl;
		return (1);
	}
    ScalarConverter::convert(argv[1]);
	return (0);
}
