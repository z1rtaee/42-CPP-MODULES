#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
    std::cout << "\n" << "========================================" << std::endl;
    std::cout << "TEST 1: Create Bureaucrats and Forms" << std::endl;
    std::cout << "========================================" << std::endl;

    try {
        Bureaucrat admin("Admin", 1);
        Bureaucrat intern("Intern", 150);
        Bureaucrat mid_level("Mid-Level", 75);

        std::cout << "\n" << admin << std::endl;
        std::cout << intern << std::endl;
        std::cout << mid_level << std::endl;

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Xuxu");
        PresidentialPardonForm pardon("Antonio");

        std::cout << "\n" << "========================================" << std::endl;
        std::cout << "TEST 2: Try to execute unsigned forms" << std::endl;
        std::cout << "========================================" << std::endl;

        std::cout << "\n[Intern tries to execute unsigned shrubbery form]" << std::endl;
        intern.executeForm(shrubbery);

        std::cout << "\n[Admin tries to execute unsigned robotomy form]" << std::endl;
        admin.executeForm(robotomy);

        std::cout << "\n========================================" << std::endl;
        std::cout << "TEST 3: Sign and execute ShrubberyCreationForm" << std::endl;
        std::cout << "========================================\n" << std::endl;

        std::cout << "[Mid-level tries to sign shrubbery (needs grade 145)]" << std::endl;
        mid_level.signForm(shrubbery);

        std::cout << "\n[Admin signs shrubbery (grade 1, can sign anything)]" << std::endl;
        admin.signForm(shrubbery);

        std::cout << "\n[Mid-level tries to execute shrubbery (needs grade 137)]" << std::endl;
        mid_level.executeForm(shrubbery);

        std::cout << "\n[Admin executes shrubbery]" << std::endl;
        admin.executeForm(shrubbery);
        
        std::cout << "\n========================================" << std::endl;
        std::cout << "TEST 4: Sign and execute RobotomyRequestForm" << std::endl;
        std::cout << "========================================\n" << std::endl;

        std::cout << "[Mid-level tries to sign robotomy (needs grade 72)]" << std::endl;
        mid_level.signForm(robotomy);

        std::cout << "\n[Admin signs robotomy]" << std::endl;
        admin.signForm(robotomy);

        std::cout << "\n[Admin executes robotomy]" << std::endl;
        admin.executeForm(robotomy);

        std::cout << "\n[Intern tries to execute robotomy (needs grade 45)]" << std::endl;
        intern.executeForm(robotomy);

        std::cout << "\n[Mid-level executes robotomy (5 times to see 50% success rate)]" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "--- Robotomy attempt " << (i + 1) << " ---" << std::endl;
            mid_level.executeForm(robotomy);
        }

        std::cout << "\n========================================" << std::endl;
        std::cout << "TEST 5: Sign and execute PresidentialPardonForm" << std::endl;
        std::cout << "========================================\n" << std::endl;

        std::cout << "[Intern tries to sign pardon (needs grade 25)]" << std::endl;
        intern.signForm(pardon);

        std::cout << "\n[Mid-level tries to sign pardon (needs grade 25)]" << std::endl;
        mid_level.signForm(pardon);

        std::cout << "\n[Admin signs pardon]" << std::endl;
        admin.signForm(pardon);

        std::cout << "\n[Mid-level tries to execute pardon (needs grade 5)]" << std::endl;
        mid_level.executeForm(pardon);

        std::cout << "\n[Admin executes pardon]" << std::endl;
        admin.executeForm(pardon);

        std::cout << "\n========================================" << std::endl;
        std::cout << "TEST 6: Test grade boundaries" << std::endl;
        std::cout << "========================================\n" << std::endl;

        Bureaucrat boundary_test("BoundaryTest", 5);
        PresidentialPardonForm test_form("test");

        std::cout << "[Bureaucrat with grade 5 signs PresidentialPardonForm (needs grade 25)]" << std::endl;
        boundary_test.signForm(test_form);

        std::cout << "\n[Bureaucrat with grade 5 executes PresidentialPardonForm (needs grade 5)]" << std::endl;
        boundary_test.signForm(test_form);
        boundary_test.executeForm(test_form);

        std::cout << "\n[Bureaucrat with grade 6 tries to execute PresidentialPardonForm (needs grade 5)]" << std::endl;
        boundary_test.decrementGrade(1);  // Now grade 6
        boundary_test.executeForm(test_form);
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n========================================" << std::endl;
    std::cout << "END OF TESTS" << std::endl;
    std::cout << "========================================\n" << std::endl;

    return 0;
}
