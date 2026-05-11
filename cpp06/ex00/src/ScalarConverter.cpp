#include "ScalarConverter.hpp"

static void printFloat(double input) {
    std::cout << BOLD << "float: " << RESET;
    float f = static_cast<float>(input);
    if (std::isnan(f))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << (f < 0 ? "-inff" : "+inff") << std::endl;
    else {
        std::cout << f;
        if (f == static_cast<int>(f)) std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

static void printDouble(double input) {
    std::cout << BOLD << "double: " << RESET;
    if (std::isnan(input))
        std::cout << "nan" << std::endl;
    else if (std::isinf(input))
        std::cout << (input < 0 ? "-inf" : "+inf") << std::endl;
    else {
        std::cout << input;
        if (input == static_cast<int>(input)) std::cout << ".0";
        std::cout << std::endl;
    }
}

static void printChar(double input) {
    std::cout << BOLD << "char: " << RESET;
    if (std::isnan(input) || std::isinf(input) || input < 0 || input > 127) {
        std::cerr << "impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(input);
    if (!std::isprint(c))
        std::cerr << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
}

static void printInt(double input) {
    std::cout << BOLD << "int: " << RESET;
    if (std::isnan(input) || std::isinf(input) ||
        input > std::numeric_limits<int>::max() ||
        input < std::numeric_limits<int>::min()) {
        std::cerr << "impossible" << std::endl;
        return;
    }
    std::cout << static_cast<int>(input) << std::endl;
}

static void printAll(double input) {
    printInt(input);
    printChar(input);
    printDouble(input);
    printFloat(input);
}

static bool isCharLiteral(const std::string& input) {
    return input.length() == 1 && !isdigit(input.at(0));
}

static bool isValidInt(const std::string& input) {
    int start = 0;
    if ((input.at(0) == '+' || input.at(0) == '-') && input.length() > 1)
        start = 1;
    for (int i = start; i < (int)input.length(); i++) {
        if (!isdigit(input.at(i)))
            return false;
    }
    return true;
}

static bool isValidExponent(const std::string& input) {
    size_t expPos = input.find_first_of("eE");
    if (expPos == std::string::npos)
        return true;
    if (expPos == 0 || expPos + 1 >= input.length())
        return false;

    size_t i = expPos + 1;
    if (input[i] == '+' || input[i] == '-')
        i++;
    if (i >= input.length())
        return false;
    while (i < input.length()) {
        if (!isdigit(input[i]))
            return false;
        i++;
    }
    return true;
}

static bool isValidFloat(const std::string& input) {
    if (input == "-inff" || input == "+inff" || input == "nanf")
        return true;
    if (input.at(input.length() - 1) != 'f' && input.at(input.length() - 1) != 'F')
        return false;
    int start = 0;
    if ((input.at(0) == '+' || input.at(0) == '-') && input.length() > 1)
        start = 1;
    int decimalCount = 0;
    int expCount = 0;
    for (int i = start; i < (int)input.length() - 1; i++) {
        char c = input.at(i);
        if (c == '.') {
            decimalCount++;
        } else if (c == 'e' || c == 'E') {
            expCount++;
        } else if ((c == '+' || c == '-') && i > start && (input.at(i - 1) == 'e' || input.at(i - 1) == 'E')) {
            continue;
        } else if (!isdigit(c)) {
            return false;
        }
    }
    if (decimalCount > 1 || expCount > 1)
        return false;
    return isValidExponent(input.substr(0, input.length() - 1));
}

static bool isValidDouble(const std::string& input) {
    if (input == "-inf" || input == "+inf" || input == "nan")
        return true;
    if (input.at(input.length() - 1) == 'f' || input.at(input.length() - 1) == 'F')
        return false;
    int start = 0;
    if ((input.at(0) == '+' || input.at(0) == '-') && input.length() > 1)
        start = 1;
    int decimalCount = 0;
    int expCount = 0;
    for (int i = start; i < (int)input.length(); i++) {
        char c = input.at(i);
        if (c == '.') {
            decimalCount++;
        } else if (c == 'e' || c == 'E') {
            expCount++;
        } else if ((c == '+' || c == '-') && i > start && (input.at(i - 1) == 'e' || input.at(i - 1) == 'E')) {
            continue;
        } else if (!isdigit(c)) {
            return false;
        }
    }
    if (decimalCount > 1 || expCount > 1)
        return false;
    return isValidExponent(input);
}

scalarType detectType(std::string input) {
    if (input.empty())
        return INV;
    else if (isCharLiteral(input))
        return CHAR;
    else if (isValidInt(input))
        return INT;
    else if (isValidFloat(input))
        return FLOAT;
    else if (isValidDouble(input))
        return DOUBLE;
    else
        return INV;
}

void ScalarConverter::convert(std::string input) {
    scalarType type = detectType(input);
    double d;

    switch (type) {
        case INV:
            std::cerr << BOLD << "char: " << RESET << "impossible" << std::endl;
            std::cerr << BOLD << "int: " << RESET << "impossible" << std::endl;
            std::cerr << BOLD << "float: " << RESET << "impossible" << std::endl;
            std::cerr << BOLD << "double: " << RESET << "impossible" << std::endl;
            break;
        case CHAR: {
            char c = input[0];
            printAll(static_cast<double>(c));
            break;
        }
        case INT: {
            long n = strtol(input.c_str(), NULL, 10);
            printAll(static_cast<double>(n));
            break;
        }
        case FLOAT: {
            if (input == "nanf") d = std::numeric_limits<double>::quiet_NaN();
            else if (input == "+inff") d = std::numeric_limits<double>::infinity();
            else if (input == "-inff") d = -std::numeric_limits<double>::infinity();
            else d = std::strtod(input.c_str(), NULL); 
            printAll(d);
            break;
        }
        case DOUBLE: {
            if (input == "nan") d = std::numeric_limits<double>::quiet_NaN();
            else if (input == "+inf") d = std::numeric_limits<double>::infinity();
            else if (input == "-inf") d = -std::numeric_limits<double>::infinity();
            else d = std::strtod(input.c_str(), NULL);
            printAll(d);
            break;
        }
    }
}

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    (void)src;
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &obj) {
    (void)obj;
    return *this;
}
