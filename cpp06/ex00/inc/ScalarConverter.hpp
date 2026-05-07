#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <cstdlib>
# include <cmath>
# include <iomanip>
# include <sstream>

# define RESET "\033[0m"
# define MAGENTA "\033[35m"
# define BOLD "\e[1;37m"

enum scalarType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INV
};

class ScalarConverter {
    private:
        ScalarConverter(); 
        ScalarConverter(const ScalarConverter &src);
        ~ScalarConverter();

        ScalarConverter &operator=(ScalarConverter &obj);

    public:
        static void convert(std::string input);
};

#endif