#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <Bureaucrat.hpp>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;
    public:
        Form();
        Form(const std::string name, const int signGrade, const int execGrade);
        Form(const Form &obj);
        ~Form();

        const std::string   getName() const;
        bool                getIsSigned() const;
        int           getSignGrade() const;
        int           getExecGrade() const;

        void    beSigned(const Bureaucrat &b);

        Form &operator=(const Form &obj);
        class GradeTooLowException : public std::exception {
            public:
                virtual const char  *what() const throw(); //this function cannot throw
        };
        class GradeTooHighException : public std::exception {
            public:
                virtual const char  *what() const throw(); //this function cannot throw      
        };

};
std::ostream    &operator<<(std::ostream &out, const Form &src);

#endif