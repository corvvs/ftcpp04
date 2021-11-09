#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {}

Cat::~Cat() {}

Cat::Cat(const Cat &from): Animal(from) {}

Cat& Cat::operator=(const Cat &rhs) {
    Animal::type = rhs.Animal::type;
    return *this;
}

void    Cat::makeSound(void) const {
    std::cout << "NYAN NYAN!" << std::endl;
}
