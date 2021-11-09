#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("default")
{
    std::cout
        << "a generic WrongAnimal has been created."
        << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type)
{
    std::cout
        << "a WrongAnimal " << type << " has been created."
        << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout
        << "a WrongAnimal " << type << " has been eaten."
        << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &from): type(from.type) {
    std::cout
        << "a WrongAnimal " << type << " has been duplicated."
        << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &rhs) {
    type = rhs.type;
    return *this;
}

const std::string&  WrongAnimal::getType(void) const {
    return type;
}

void    WrongAnimal::makeSound(void) const {
    std::cout << "WrongAnimal WrongAnimal!" << std::endl;
}
