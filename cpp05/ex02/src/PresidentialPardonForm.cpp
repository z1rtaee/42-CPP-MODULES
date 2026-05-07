#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
    _target = "Default";
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "PresidentialPardonForm Default Constructor called for " << MAGENTA << this->getName()
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << this->getSignGrade() << RESET 
    << " and an execution grade of " << MAGENTA << this->getExecGrade() << RESET << "!" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5) {
    _target = target;
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "PresidentialPardonForm Constructor called for " << MAGENTA << this->getName()
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << this->getSignGrade() << RESET 
    << " and an execution grade of " << MAGENTA << this->getExecGrade() << RESET << "!" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj) {
    *this = obj;
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "PresidentialPardonForm Default Constructor called for " << MAGENTA << this->getName()
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << this->getSignGrade() << RESET 
    << " and an execution grade of " << MAGENTA << this->getExecGrade() << RESET << "!" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "PresidentialPardonForm Destructor called for " << MAGENTA << this->getName() 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << this->getSignGrade() << RESET 
    << " and an execution grade of " << MAGENTA << this->getExecGrade() << "!" << RESET << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	(void)other;
	return *this;
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
        throw (FormNotSignedException());
    else if (executor.getGrade() > this->getExecGrade())
        throw (GradeTooLowException());
    else {
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}

std::ostream    &operator<<(std::ostream &out, const PresidentialPardonForm &src) {
    out << src.getName() << ", form signed: " << (src.getIsSigned() ? "true" : "false")
        << ", sign grade " << src.getSignGrade()
        << ", exec grade " << src.getExecGrade();
    return out;
}
