#include "Bureaucrat.hpp"

const char  *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade is too high!";
}

const char  *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too low!";
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Bureaucrat Default constructor called for " << MAGENTA << _name 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a grade of " << MAGENTA << _grade << RESET << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Bureaucrat Default Destructor called for " << MAGENTA << _name 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a grade of " << MAGENTA << _grade << RESET << std::endl;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &obj) {
    if (this != &obj)
        this->_grade = obj.getGrade();
    return *this;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    this->setGrade(grade);
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Bureaucrat constructor called for " << MAGENTA << _name 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a grade of " << MAGENTA << _grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name), _grade(obj._grade) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Bureaucrat Copy constructor called for " << MAGENTA << _name 
    << RESET << " (˶ᵔ ᵕ ᵔ˶)" << " with a grade of " << MAGENTA << _grade << RESET << std::endl;
    *this = obj;
}

int    Bureaucrat::getGrade() const {
    return this->_grade;
}

const std::string    Bureaucrat::getName() const {
    return this->_name;
}

void    Bureaucrat::setGrade(int grade) {
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade = grade;
}

void Bureaucrat::incrementGrade(int inc) {
    if (this->_grade - inc < 1)
        throw Bureaucrat::GradeTooHighException();
    this->setGrade(this->_grade - inc);
}

void Bureaucrat::decrementGrade(int dec) {
    if (this->_grade + dec > 150)
        throw Bureaucrat::GradeTooLowException();
    this->setGrade(this->_grade + dec);
}

void Bureaucrat::signForm(Form &f) {
    try {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) {
    out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
    return out;
}
