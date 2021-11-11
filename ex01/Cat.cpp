#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), brain_(new Brain()) {
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a Cat has arrived."
        << Constants::kTextReset << std::endl;
}

Cat::~Cat() {
    if (brain_) {
        delete brain_;
    }
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a Cat has gotten out."
        << Constants::kTextReset << std::endl;
}

Cat::Cat(const Cat &from): Animal(from) {
    if (from.brain_) {
        brain_ = new Brain(*(from.brain_));
    } else {
        brain_ = NULL;
    }
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a Cat has duplicated."
        << Constants::kTextReset << std::endl;
}

Cat& Cat::operator=(const Cat &rhs) {
    Animal::type = rhs.Animal::type;
    delete brain_;
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
        std::cout
            << Constants::kTextWarning
            << "[" << this << "] "
            << "(the cat has no ideas...)"
            << Constants::kTextReset << std::endl;
        return;
    }
    std::cout
        << Constants::kTextInfo
        << "[" << this << "] "
        << "a cerebral: "
        << brain_
        << Constants::kTextReset << std::endl;
    brain_->showIdeas();
}
