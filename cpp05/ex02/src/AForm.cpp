#include "AForm.hpp"

const char  *AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high!";
}

const char  *AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low!";
}

const char  *AForm::FormNotSignedException::what() const throw() {
    return "AForm should be signed before execution!";
}

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "AForm Default Constructor called for " << MAGENTA << _name 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << _signGrade << RESET 
    << " and an execution grade of " << MAGENTA << _execGrade << RESET << "!" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "AForm Constructor called for " << MAGENTA << _name 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << _signGrade << RESET 
    << " and an execution grade of " << MAGENTA << _execGrade << RESET << "!" << std::endl;
    if (this->_signGrade > 150 || this->_execGrade > 150)
        throw AForm::GradeTooLowException();
    else if (this->_signGrade < 1 || this->_execGrade < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &obj) : _name(obj.getName()), _isSigned(false), _signGrade(obj.getSignGrade()), _execGrade(obj.getExecGrade()) { 
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "AForm Copy Constructor called for " << MAGENTA << _name 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << _signGrade << RESET 
    << " and an execution grade of " << MAGENTA << _execGrade << RESET << "!" << std::endl;
    *this = obj;
}

AForm  &AForm::operator=(const AForm &obj) {
    if (this != &obj)
        this->_isSigned = obj.getIsSigned();
    return *this;
}

AForm::~AForm() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "AForm Destructor called for " << MAGENTA << _name 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << _signGrade << RESET 
    << " and an execution grade of " << MAGENTA << _execGrade << "!" << std::endl;
}

const std::string AForm::getName() const {
    return this->_name;
}

bool AForm::getIsSigned() const {
    return this->_isSigned;
}

int AForm::getSignGrade() const {
    return this->_signGrade;
}

int AForm::getExecGrade() const {
    return this->_execGrade;
}

std::string AForm::getTarget(void) const
{
	return (_target);
}

std::ostream    &operator<<(std::ostream &out, const AForm &src) {
    out << src.getName() << ", form signed: " << (src.getIsSigned() ? "true" : "false")
        << ", sign grade " << src.getSignGrade()
        << ", exec grade " << src.getExecGrade();
    return out;
}

void    AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->_signGrade)
        throw AForm::GradeTooLowException();
    else {
        this->_isSigned = true;
    }

}

