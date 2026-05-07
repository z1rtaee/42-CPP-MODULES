#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
    _target = "Default";
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "ShrubberyCreationForm Default Constructor called for " << MAGENTA << this->getName()
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << this->getSignGrade() << RESET 
    << " and an execution grade of " << MAGENTA << this->getExecGrade() << RESET << "!" << RESET<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137) {
    _target = target;
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "ShrubberyCreationForm Constructor called for " << MAGENTA << this->getName()
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << this->getSignGrade() << RESET 
    << " and an execution grade of " << MAGENTA << this->getExecGrade() << RESET << "!" << RESET<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj) {
    *this = obj;
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "ShrubberyCreationForm Copy Constructor called for " << MAGENTA << this->getName()
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << this->getSignGrade() << RESET 
    << " and an execution grade of " << MAGENTA << this->getExecGrade() << RESET << "!" << RESET<< std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "ShrubberyCreationForm Destructor called for " << MAGENTA << this->getName() 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << this->getSignGrade() << RESET 
    << " and an execution grade of " << MAGENTA << this->getExecGrade() << "!" << RESET << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	(void)other;
	return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
        throw (FormNotSignedException());
    else if (executor.getGrade() > this->getExecGrade())
        throw (GradeTooLowException());
    else { 
        std::ofstream outfile;
        outfile.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::trunc);
        if (!outfile.is_open()) {
            std::cerr << "Error: Couldn't open " << this->getTarget() + "_shrubbery" << " file!" << std::endl;
        }
        outfile << TREE << std::endl;
        outfile.close();
    }
}


std::ostream    &operator<<(std::ostream &out, const ShrubberyCreationForm &src) {
    out << src.getName() << ", form signed: " << (src.getIsSigned() ? "true" : "false")
        << ", sign grade " << src.getSignGrade()
        << ", exec grade " << src.getExecGrade();
    return out;
}
