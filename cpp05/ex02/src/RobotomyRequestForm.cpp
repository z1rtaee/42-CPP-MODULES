#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
    srand(time(0));
    _target = "Default";
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "RobotomyRequestForm Default Constructor called for " << MAGENTA << this->getName()
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << this->getSignGrade() << RESET 
    << " and an execution grade of " << MAGENTA << this->getExecGrade() << RESET << "!" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45) {
    _target = target;
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "RobotomyRequestForm Constructor called for " << MAGENTA << this->getName()
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << this->getSignGrade() << RESET 
    << " and an execution grade of " << MAGENTA << this->getExecGrade() << RESET << "!" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj) {
    *this = obj;
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "RobotomyRequestForm CopyConstructor called for " << MAGENTA << this->getName()
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << this->getSignGrade() << RESET 
    << "and an execution grade of " << MAGENTA << this->getExecGrade() << RESET << "!" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "RobotomyRequestForm Destructor called for " << MAGENTA << this->getName() 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << this->getSignGrade() << RESET 
    << " and an execution grade of " << MAGENTA << this->getExecGrade() << "!" << RESET << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	(void)other;
	return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
        throw (FormNotSignedException());
    else if (executor.getGrade() > this->getExecGrade())
        throw (GradeTooLowException());
    else {
        std::cout << "bzzzzzzzzzzzzz.......... beep... boop... HMMMMMMMMMMM " << "\n\t **and some more drilling noises** " << std::endl;
        if (rand() % 2)
            std::cout << MAGENTA << this->getTarget() << RESET << " has been robotomized successfully." << std::endl;
        else
            std::cout << MAGENTA << this->getTarget() << RESET << " robotomy failed." << std::endl;
    }    
}


std::ostream    &operator<<(std::ostream &out, const RobotomyRequestForm &src) {
    out << src.getName() << ", form signed: " << (src.getIsSigned() ? "true" : "false")
        << ", sign grade " << src.getSignGrade()
        << ", exec grade " << src.getExecGrade();
    return out;
}
