#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
		std::cerr << "Valid levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}
	
	Harl harl;
	harl.complainFilter(argv[1]);
	
	return 0;
}