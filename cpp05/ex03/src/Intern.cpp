#include "Intern.hpp"

static AForm *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

Intern::Intern() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Intern Default constructor called " << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Intern::Intern(const Intern &src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Intern Copy constructor called " << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    (void)src;
}

Intern::~Intern() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Intern Default Destructor called " << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Intern& Intern::operator=(const Intern &obj) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Intern Copy Assignment called " << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    (void)obj;
    return *this;
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
    const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*creators[3])(const std::string &) = {createShrubbery, createRobotomy, createPresidential};
    const std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Intern creates " << MAGENTA << formNames[i] << RESET << std::endl;
            return creators[i](formTarget);
        }
    }
    std::cerr << MAGENTA << ".✦ ݁˖ " << BOLD << "Intern cannot create " << MAGENTA << formName << RESET << " because it does not exist." << RESET << std::endl;
    return NULL;
}
