#include "Harl.hpp"

Harl::Harl( void )
{
	std::cout << "Harl has entered the building!" << std::endl;
}

Harl::~Harl( void )
{
	std::cout << "Harl has left the building..." << std::endl;
}

void Harl::debug( void )
{
	std::cout << "[DEBUG] ";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[INFO] ";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[WARNING] ";
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ERROR] ";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	// Array of strings representing the levels
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	
	// Array of pointers to member functions
	void (Harl::*functions[4])( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	
	// Loop through levels to find the matching one
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])(); // Call the appropriate function using pointer to member function
			return;
		}
	}
	std::cout << "[UNKNOWN] Harl doesn't know how to complain about: " << level << std::endl;
}