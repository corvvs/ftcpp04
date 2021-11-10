#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria &from): type(from.type) {}

AMateria&   AMateria::operator=(const AMateria &rhs) {
    (std::string)type = rhs.type;
    return *this;
}

std::string const & AMateria::getType() const {
    return type;
}

void    AMateria::use(ICharacter& target) {
    (void) target;
    std::cout << "* makes no sense *" << std::endl;
}
