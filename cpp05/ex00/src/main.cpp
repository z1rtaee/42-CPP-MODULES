#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "== Normal behavior ==\n";
	try {
		Bureaucrat a("Bebedrigo", 2);
		std::cout << a << std::endl;
		a.incrementGrade(1); // goes to 1
		std::cout << "After increment: " << a << std::endl;
		// this will throw
		a.incrementGrade(1);
	}
	catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what();
	}

	std::cout << "\n\n== Construction errors ==\n";
	try {
		Bureaucrat b("Alvesamigo", 151);
	}
	catch (std::exception &e) {
		std::cerr << "Caught exception creating Alvesamigo: " << e.what();
	}
    std::cout << std::endl;
	try {
		Bureaucrat c("Joao", 0);
	}
	catch (std::exception &e) {
		std::cerr << "Caught exception creating Joao: " << e.what();
	}

	std::cout << "\n\n== Decrement to low ==\n";
	try {
		Bureaucrat d("Thay", 149);
		std::cout << d << std::endl;
		d.decrementGrade(2); // should throw
	}
	catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what();
	}

	std::cout << "\n\n== Copy and assign ==\n";
	Bureaucrat e("Copy Bebedrigo", 42);
	Bureaucrat f = e; // copy ctor
	std::cout << "Copied: " << f << std::endl;
	Bureaucrat g("Bebedrigo igualado", 100);
	g = e; // assignment (copies grade only)
	std::cout << "Assigned: " << g << std::endl;

	return 0;
}