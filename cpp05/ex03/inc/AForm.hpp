#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <Bureaucrat.hpp>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;

    protected:
        std::string _target;

    public:
        AForm();
        AForm(const std::string name, const int signGrade, const int execGrade);
        AForm(const AForm &obj);
        virtual ~AForm();

        const std::string   getName() const;
        bool                getIsSigned() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;
        std::string         getTarget(void) const;

        AForm &operator=(const AForm &obj);
        
        void            beSigned(const Bureaucrat &b);
        virtual void    execute(Bureaucrat const & executor) const = 0;

        class GradeTooLowException : public std::exception {
            public:
                virtual const char  *what() const throw(); //this function cannot throw
        };
        class GradeTooHighException : public std::exception {
            public:
                virtual const char  *what() const throw(); //this function cannot throw      
        };
        class FormNotSignedException : public std::exception {
            public:
                virtual const char  *what() const throw(); //this function cannot throw      
        };

};
std::ostream    &operator<<(std::ostream &out, const AForm &src);

#endif