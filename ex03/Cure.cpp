#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &from): AMateria(from) {}

Cure& Cure::operator=(const Cure &rhs) {
    (void)rhs;
    std::cout
        << Constants::kTextInfo
        << "Cure::operator=(const Cure &rhs)"
        << Constants::kTextReset << std::endl;
    return *this;
}

Cure* Cure::clone() const {
    return new Cure(*this);
}

void    Cure::use(ICharacter& target) {
    std::cout
        << "* heals " << target.getName() << "’s wounds *"
        << std::endl;
}
