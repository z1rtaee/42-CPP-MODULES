#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "\n=== " << "Construction checks" << " ===" << std::endl;
	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
		std::cout << tooHigh << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught Bureaucrat construction error: " << e.what() << std::endl;
	}

	try
	{
		Form badForm("Broken", 0, 10);
		std::cout << badForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught Form construction error: " << e.what() << std::endl;
	}

	std::cout << "\n=== " << "Valid objects" << " ===" << std::endl;
	Bureaucrat bebedrigo("Bebedrigo", 42);
	Bureaucrat thay("Thay", 1);
	Form test1("Test 1", 50, 20);
	Form test2("Test 2", 5, 3);

	std::cout << bebedrigo << std::endl;
	std::cout << thay << std::endl;
	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;

	std::cout << "\n=== " << "Signing attempts" << " ===" << std::endl;
	bebedrigo.signForm(test1);
	bebedrigo.signForm(test2);
	thay.signForm(test2);

	std::cout << "\n=== " << "Direct beSigned check" << " ===" << std::endl;
	try
	{
		test1.beSigned(thay);
		std::cout << test1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n=== " << "Final States" << " ===" << std::endl;
	std::cout << bebedrigo << std::endl;
	std::cout << thay << std::endl;
	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;

	return 0;
}
