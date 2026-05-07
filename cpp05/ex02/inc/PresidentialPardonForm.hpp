#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <AForm.hpp>
# include <iostream>

class PresidentialPardonForm : public AForm{
    public:
        PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		virtual ~PresidentialPardonForm();

        PresidentialPardonForm& operator=(const PresidentialPardonForm &other);

        void    execute(Bureaucrat const &executor) const;
};

std::ostream    &operator<<(std::ostream &out, const PresidentialPardonForm &src);


#endif