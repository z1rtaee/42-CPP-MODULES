#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <cstdio>
# include <ctime>
# include <exception>


# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define BOLD "\e[1;37m"

class Base {
    public:
        virtual ~Base();
};

#endif