#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), brain_(new Brain()) {
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a Dog has come."
        << Constants::kTextReset << std::endl;
}

Dog::~Dog() {
    if (brain_) {
        delete brain_;
    }
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a Dog has gone."
        << Constants::kTextReset << std::endl;
}

Dog::Dog(const Dog &from): Animal(from) {
    if (from.brain_) {
        brain_ = new Brain(*(from.brain_));
    } else {
        brain_ = NULL;
    }
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "a Dog has duplicated."
        << Constants::kTextReset << std::endl;
}

Dog& Dog::operator=(const Dog &rhs) {
    Animal::type = rhs.Animal::type;
    delete brain_;
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
        std::cout
            << Constants::kTextWarning
            << "[" << this << "] "
            << "(the dog has no ideas...)"
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
