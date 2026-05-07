#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
    public:
		Intern();
		Intern(const Intern &src);
		~Intern();
        
		Intern& operator=(const Intern &obj);
		
        AForm	*makeForm(std::string formName, std::string formTarget);
};

#endif