#include "Harl.hpp"

int main( void )
{
	Harl harl;

	std::cout << "\n=== Testing Harl's Complaint System ===" << std::endl;
	std::cout << "\n--- Testing DEBUG level ---" << std::endl;
	harl.complain("DEBUG");

	std::cout << "\n--- Testing INFO level ---" << std::endl;
	harl.complain("INFO");

	std::cout << "\n--- Testing WARNING level ---" << std::endl;
	harl.complain("WARNING");

	std::cout << "\n--- Testing ERROR level ---" << std::endl;
	harl.complain("ERROR");

	std::cout << "\n--- Testing invalid level ---" << std::endl;
	harl.complain("INVALID");

	std::cout << "\n--- More complaints from Harl ---" << std::endl;
	harl.complain("DEBUG");
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("WARNING");

	std::cout << "\n--- Testing case sensitivity ---" << std::endl;
	harl.complain("debug"); // Should not work
	harl.complain("Debug"); // Should not work

	std::cout << "\n=== End of tests ===\n" << std::endl;

	return 0;
}