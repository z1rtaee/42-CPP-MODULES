#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <iomanip>
# include <string>

/*colors :D*/
# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define BOLD "\e[1;37m"

class Brain {
    public:
        Brain();
        Brain(const Brain& src);
        Brain& operator=(const Brain& obj);
        ~Brain();

        void setIdea(int index, const std::string &idea);
        std::string getIdea(int index) const;

    private:
        std::string ideas[100];
};

#endif