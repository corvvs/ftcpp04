#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), brain_(new Brain()) {
    std::cout
        << "a Cat has arrived."
        << std::endl;
}

Cat::~Cat() {
    if (brain_) {
        delete brain_;
    }
    std::cout
        << "a Cat has gotten out."
        << std::endl;
}

Cat::Cat(const Cat &from): Animal(from) {
    if (from.brain_) {
        brain_ = new Brain(*(from.brain_));
    } else {
        brain_ = NULL;
    }
}

Cat& Cat::operator=(const Cat &rhs) {
    Animal::type = rhs.Animal::type;
    if (rhs.brain_) {
        brain_ = new Brain(*(rhs.brain_));
    } else {
        brain_ = NULL;
    }
    return *this;
}

void    Cat::makeSound(void) const {
    std::cout << "NYAN NYAN!" << std::endl;
}


void    Cat::showIdeas(void) const {
    if (!brain_) {
        std::cout << "(the cat has no ideas...)" << std::endl;
        return;
    }
    std::cout
        << "a cerebral: "
        << brain_
        << std::endl;
    brain_->showIdeas();
}
