#include "ScalarConverter.hpp"

static scalarType detectType(std::string input) {
    // Check for char literal: 'c'
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
        return CHAR;
    }
    if (input == "-inff" || input == "+inff" || input == "nanf") {
        return FLOAT;
    }
    
    // Check for special double values
    if (input == "-inf" || input == "+inf" || input == "nan") {
        return DOUBLE;
    }
    
    // Check for float (ends with 'f')
    if (input.length() > 0 && input[input.length() - 1] == 'f') {
        return FLOAT;
    }
    
    // Check for double (contains '.')
    if (input.find('.') != std::string::npos) {
        return DOUBLE;
    }
    
    // Check if it's a valid integer
    bool isInt = true;
    size_t start = 0;
    if (input.length() > 0 && (input[0] == '-' || input[0] == '+')) {
        start = 1;
    }
    for (size_t i = start; i < input.length(); i++) {
        if (!std::isdigit(input[i])) {
            isInt = false;
            break;
        }
    }
    
    if (isInt && input.length() > start) {
        return INT;
    }
    
    return INV;
}

void ScalarConverter::convert(std::string input) {
    scalarType type = detectType(input);
    
    if (type == CHAR) {
        char c = input[1];
        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
    else if (type == INT) {
        int intVal = std::stoi(input);
        std::cout << "char: ";
        if (intVal >= 0 && intVal <= 127 && std::isprint(intVal)) {
            std::cout << static_cast<char>(intVal) << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
        std::cout << "int: " << intVal << std::endl;
        std::cout << "float: " << static_cast<float>(intVal) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(intVal) << ".0" << std::endl;
    }
    else if (type == FLOAT) {
        float floatVal = std::stof(input);
        std::cout << "char: ";
        if (std::isnan(floatVal) || std::isinf(floatVal)) {
            std::cout << "impossible" << std::endl;
        } else if (floatVal >= 0 && floatVal <= 127 && std::isprint(static_cast<char>(floatVal))) {
            std::cout << static_cast<char>(floatVal) << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
        
        std::cout << "int: ";
        if (std::isnan(floatVal) || std::isinf(floatVal)) {
            std::cout << "impossible" << std::endl;
        } else {
            std::cout << static_cast<int>(floatVal) << std::endl;
        }
        
        std::cout << "float: " << floatVal << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(floatVal) << std::endl;
    }
    else if (type == DOUBLE) {
        double doubleVal = std::stod(input);
        std::cout << "char: ";
        if (std::isnan(doubleVal) || std::isinf(doubleVal)) {
            std::cout << "impossible" << std::endl;
        } else if (doubleVal >= 0 && doubleVal <= 127 && std::isprint(static_cast<char>(doubleVal))) {
            std::cout << static_cast<char>(doubleVal) << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
        
        std::cout << "int: ";
        if (std::isnan(doubleVal) || std::isinf(doubleVal)) {
            std::cout << "impossible" << std::endl;
        } else {
            std::cout << static_cast<int>(doubleVal) << std::endl;
        }
        
        std::cout << "float: " << static_cast<float>(doubleVal) << "f" << std::endl;
        std::cout << "double: " << doubleVal << std::endl;
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
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

