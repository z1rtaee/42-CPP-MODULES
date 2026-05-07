#include "Intern.hpp"

int main(void) {
	std::cout << "\n" << "========================================" << std::endl;
	std::cout << "TEST 1: Create Intern and Bureaucrat" << std::endl;
	std::cout << "========================================" << std::endl;

	try {
		Intern someRandomIntern;
		Bureaucrat boss("Boss", 1);

		std::cout << "\n" << boss << std::endl;

		std::cout << "\n" << "========================================" << std::endl;
		std::cout << "TEST 2: Make valid forms" << std::endl;
		std::cout << "========================================" << std::endl;

		AForm *shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
		AForm *robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Marvin");

		std::cout << "\n" << "========================================" << std::endl;
		std::cout << "TEST 3: Sign and execute forms" << std::endl;
		std::cout << "========================================" << std::endl;

		if (shrubbery != NULL)
		{
			boss.signForm(*shrubbery);
			boss.executeForm(*shrubbery);
			delete shrubbery;
		}
		if (robotomy != NULL)
		{
			boss.signForm(*robotomy);
			boss.executeForm(*robotomy);
			delete robotomy;
		}
		if (pardon != NULL)
		{
			boss.signForm(*pardon);
			boss.executeForm(*pardon);
			delete pardon;
		}

		std::cout << "\n" << "========================================" << std::endl;
		std::cout << "TEST 4: Invalid form name" << std::endl;
		std::cout << "========================================" << std::endl;

		AForm *invalid = someRandomIntern.makeForm("coffee request", "kitchen");
		if (invalid != NULL)
			delete invalid;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n" << "========================================" << std::endl;
	std::cout << "END OF TESTS" << std::endl;
	std::cout << "========================================\n" << std::endl;

	return 0;
}
