#include "IceMateria.hpp"

IceMateria::IceMateria(): AMateria("ice") {}

IceMateria::~IceMateria() {}

IceMateria::IceMateria(const IceMateria &from): AMateria(from) {}

IceMateria& IceMateria::operator=(const IceMateria &rhs) {
    (void)rhs;
    return *this;
}

IceMateria* IceMateria::clone() const {
    return new IceMateria(*this);
}

void    IceMateria::use(ICharacter& target) {
    std::cout
        << "* shoots an ice bolt at "
        << target.getName()
        << " *"
        << std::endl;
}
