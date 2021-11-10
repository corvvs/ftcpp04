#include "AMateria.hpp"
#include "Constants.hpp"

AMateria::AMateria(std::string const & type): type(type) {
    std::cout
        << Constants::kTextInfo
        << type << " Materia has been created."
        << Constants::kTextReset << std::endl;
}

AMateria::~AMateria() {
    std::cout
        << Constants::kTextInfo
        << type << " Materia has been destroyed."
        << Constants::kTextReset << std::endl;
}

AMateria::AMateria(const AMateria &from): type(from.type) {
    std::cout
        << Constants::kTextInfo
        << type << " Materia has been cloned."
        << Constants::kTextReset << std::endl;
}

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
