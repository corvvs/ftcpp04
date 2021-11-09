#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {}

WrongCat::~WrongCat() {}

WrongCat::WrongCat(const WrongCat &from): WrongAnimal(from) {}

WrongCat& WrongCat::operator=(const WrongCat &rhs) {
    WrongAnimal::type = rhs.WrongAnimal::type;
    return *this;
}

void    WrongCat::makeSound(void) const {
    std::cout << "NYASO NYASO!" << std::endl;
}
