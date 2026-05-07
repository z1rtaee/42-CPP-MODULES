#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <AForm.hpp>
# include <iostream>
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm{
    public:
        RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		virtual ~RobotomyRequestForm();
		
        RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

        void    execute(Bureaucrat const &executor) const;
};

std::ostream    &operator<<(std::ostream &out, const RobotomyRequestForm &src);

#endif