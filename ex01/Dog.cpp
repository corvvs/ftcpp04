#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), brain_(new Brain()) {
    std::cout
        << "a Dog has come."
        << std::endl;
}

Dog::~Dog() {
    if (brain_) {
        delete brain_;
    }
    std::cout
        << "a Dog has gone."
        << std::endl;
}

Dog::Dog(const Dog &from): Animal(from) {
    if (from.brain_) {
        brain_ = new Brain(*(from.brain_));
    } else {
        brain_ = NULL;
    }
}

Dog& Dog::operator=(const Dog &rhs) {
    Animal::type = rhs.Animal::type;
    if (rhs.brain_) {
        brain_ = new Brain(*(rhs.brain_));
    } else {
        brain_ = NULL;
    }
    return *this;
}

void    Dog::makeSound(void) const {
    std::cout << "WAN WAN!" << std::endl;
}

void    Dog::showIdeas(void) const {
    if (!brain_) {
        std::cout << "(the dog has no ideas...)" << std::endl;
        return;
    }
    std::cout
        << "a cerebral: "
        << brain_
        << std::endl;
    brain_->showIdeas();
}
