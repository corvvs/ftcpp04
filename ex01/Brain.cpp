#include "Brain.hpp"

static std::size_t brain_index = 0;

Brain::Brain() {
    std::stringstream ss;
    for (std::size_t i = 0; i < Brain::N; i += 1) {
        ss << brain_index;
        ss << "_";
        ss << i;
        ss >> ideas[i];
        ss.clear();
    }
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "the Brain no "
        << brain_index
        << ". has been composed."
        << Constants::kTextReset << std::endl;
    brain_index += 1;
}

Brain::~Brain() {
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a Brain has been decomposed."
        << Constants::kTextReset << std::endl;
}

Brain::Brain(const Brain &from) {
    for (std::size_t i = 0; i < Brain::N; i += 1) {
        ideas[i] = from.ideas[i];
    }
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a Brain has duplicated."
        << Constants::kTextReset << std::endl;
}

Brain& Brain::operator=(const Brain &rhs) {
    for (std::size_t i = 0; i < Brain::N; i += 1) {
        ideas[i] = rhs.ideas[i];
    }
    return *this;
}

const std::string*  Brain::getIdeas(void) const {
    return ideas;
}

void    Brain::showIdeas(void) const {
    for (std::size_t i = 0; i < Brain::N; i += 1) {
        std::cout << ideas[i] << std::endl;
    }
}
