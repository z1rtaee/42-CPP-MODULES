#include "Form.hpp"

const char  *Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char  *Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

Form::Form() : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Form Default Constructor called for " << MAGENTA << _name 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << _signGrade << RESET 
    << "and an execution grade of " << MAGENTA << _execGrade << RESET << ". This Form is currently unsigned!" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Form Constructor called for " << MAGENTA << _name 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << _signGrade << RESET 
    << "and an execution grade of " << MAGENTA << _execGrade << RESET << ". This Form is currently unsigned!" << std::endl;
    if (this->_signGrade > 150 || this->_execGrade > 150)
        throw Form::GradeTooLowException();
    else if (this->_signGrade < 1 || this->_execGrade < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form &obj) : _name(obj.getName()), _isSigned(false), _signGrade(obj.getSignGrade()), _execGrade(obj.getExecGrade()) { 
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Form Copy Constructor called for " << MAGENTA << _name 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << _signGrade << RESET 
    << "and an execution grade of " << MAGENTA << _execGrade << RESET << ". This Form is currently unsigned!" << std::endl;
    *this = obj;
}

Form  &Form::operator=(const Form &obj) {
    if (this != &obj)
        this->_isSigned = obj.getIsSigned();
    return *this;
}

Form::~Form() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Form Destructor called for " << MAGENTA << _name 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a sign grade of " << MAGENTA << _signGrade << RESET 
    << "and an execution grade of " << MAGENTA << _execGrade << ". This Form was unsigned!" << std::endl;
}

const std::string Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
}

int Form::getSignGrade() const {
    return this->_signGrade;
}

int Form::getExecGrade() const {
    return this->_execGrade;
}

std::ostream    &operator<<(std::ostream &out, const Form &src) {
    out << src.getName() << ", form signed: " << (src.getIsSigned() ? "true" : "false")
        << ", sign grade " << src.getSignGrade()
        << ", exec grade " << src.getExecGrade();
    return out;
}

void    Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->_signGrade)
        throw Form::GradeTooLowException();
    else {
        this->_isSigned = true;
    }

}