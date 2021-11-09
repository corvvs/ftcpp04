#include "Animal.hpp"

Animal::Animal(): type("default")
{
    std::cout
        << "a generic Animal has been created."
        << std::endl;
}

Animal::Animal(std::string type): type(type)
{
    std::cout
        << "an Animal " << type << " has been created."
        << std::endl;
}

Animal::~Animal() {
    std::cout
        << "an Animal " << type << " has been eaten."
        << std::endl;
}

Animal::Animal(const Animal &from): type(from.type) {
    std::cout
        << "an Animal " << type << " has been duplicated."
        << std::endl;
}

Animal& Animal::operator=(const Animal &rhs) {
    type = rhs.type;
    return *this;
}

const std::string&  Animal::getType(void) const {
    return type;
}

void    Animal::makeSound(void) const {
    std::cout << "Animal Animal!" << std::endl;
}

void    Animal::showIdeas(void) const {
    std::cout << "(no ideas...)" << std::endl;
}
