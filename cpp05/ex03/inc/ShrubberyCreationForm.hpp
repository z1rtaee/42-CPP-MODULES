#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <AForm.hpp>
# include <iostream>
# include <fstream>

# define TREE "\n \
\n\
──▒▒▒▒▒▒▒▒───▒▒▒▒▒▒▒▒\n\
─▒▐▒▐▒▒▒▒▌▒─▒▒▌▒▒▐▒▒▌▒\n\
──▒▀▄█▒▄▀▒───▒▀▄▒▌▄▀▒\n\
─────██─────────██\n\
░░░▄▄██▄░░░░░░░▄██▄░░░\n\
Tree"

class ShrubberyCreationForm : public AForm{
    public:
        ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm();
		
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);

        void    execute(Bureaucrat const &executor) const;
};

std::ostream    &operator<<(std::ostream &out, const ShrubberyCreationForm &src);

#endif