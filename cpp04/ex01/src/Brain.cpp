#include "Brain.hpp"

Brain::Brain() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Brain Default constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Brain::Brain(const Brain &src) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Brain Copy constructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = src.ideas[i];
    }
}

Brain::~Brain() {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Brain Default destructor called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
}

Brain  &Brain::operator=(const Brain &obj) {
    std::cout << MAGENTA << ".✦ ݁˖ " << BOLD << "Brain Copy assignment called" << MAGENTA << " (˶ᵔ ᵕ ᵔ˶)" << RESET << std::endl;
    if (this != &obj) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = obj.ideas[i];
        }
    }   
    return *this;
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}

