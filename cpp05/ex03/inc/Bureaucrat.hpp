#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include <stdexcept>
# include <AForm.hpp>

# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define BOLD "\e[1;37m"

class AForm;

class Bureaucrat {
    private:
        const std::string _name;
        int   _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat();

        Bureaucrat  &operator=(const Bureaucrat &obj);

        const std::string getName(void) const;
        int     getGrade(void) const;
        void    setGrade(int grade);

        void    incrementGrade(int inc);
        void    decrementGrade(int dec);
        void    signForm(AForm &f);
        void    executeForm(AForm const & form) const;

        class GradeTooLowException : public std::exception {
            public:
                virtual const char  *what() const throw(); //this function cannot throw

        };
        class GradeTooHighException : public std::exception {
            public:
                virtual const char  *what() const throw(); //this function cannot throw
                
        };
} ;

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &src);

#endif

