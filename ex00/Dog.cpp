#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
    std::cout
        << "a Dog has come."
        << std::endl;
}

Dog::~Dog() {
    std::cout
        << "a Dog has gone."
        << std::endl;
}

Dog::Dog(const Dog &from): Animal(from) {}

Dog& Dog::operator=(const Dog &rhs) {
    Animal::type = rhs.Animal::type;
    return *this;
}

void    Dog::makeSound(void) const {
    std::cout << "WAN WAN!" << std::endl;
}
