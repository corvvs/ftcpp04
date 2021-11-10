#include "AMateria.hpp"

AMateria::AMateria(): type("<typeless>") {
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "A typeless Materia has been <created>"
        << Constants::kTextReset << std::endl;
}

AMateria::AMateria(std::string const & type): type(type) {
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << type << " Materia has been <created>"
        << Constants::kTextReset << std::endl;
}

AMateria::~AMateria() {
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << type << " Materia has been <destroyed>"
        << Constants::kTextReset << std::endl;
}

AMateria::AMateria(const AMateria &from): type(from.type) {
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << type << " Materia has been <cloned>"
        << Constants::kTextReset << std::endl;
}

AMateria&   AMateria::operator=(const AMateria &rhs) {
    (void)rhs;
    std::cout
        << Constants::kTextWarning
        << "AMateria::operator=(const AMateria &rhs)"
        << Constants::kTextReset << std::endl;
    return *this;
}

std::string const & AMateria::getType() const {
    return type;
}

void    AMateria::use(ICharacter& target) {
    (void) target;
    std::cout << "* makes no sense *" << std::endl;
}
