#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &from): AMateria(from) {}

Ice& Ice::operator=(const Ice &rhs) {
    (void)rhs;
    std::cout
        << Constants::kTextInfo
        << "Ice::operator=(const Ice &rhs)"
        << Constants::kTextReset << std::endl;
    return *this;
}

Ice* Ice::clone() const {
    return new Ice(*this);
}

void    Ice::use(ICharacter& target) {
    std::cout
        << "* shoots an ice bolt at "
        << target.getName()
        << " *"
        << std::endl;
}
