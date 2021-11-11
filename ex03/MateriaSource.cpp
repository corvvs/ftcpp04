#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (std::size_t i = 0; i < MateriaSource::kMaxMateria; i += 1) {
        materias[i] = NULL;
    }
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "A MateriaSource has been <created>"
        << Constants::kTextReset << std::endl;
}

MateriaSource::~MateriaSource() {
    for (std::size_t i = 0; i < MateriaSource::kMaxMateria; i += 1) {
        delete materias[i];
    }
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "A MateriaSource has been <destroyed>"
        << Constants::kTextReset << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& from) {
    for (std::size_t i = 0; i < MateriaSource::kMaxMateria; i += 1) {
        materias[i] = from.materias[i] ? from.materias[i]->clone() : NULL;
    }
    std::cout
        << Constants::kTextLifeCycle
        << "[" << this << "] "
        << "A MateriaSource has been <cloned>"
        << Constants::kTextReset << std::endl;
}

MateriaSource&  MateriaSource::operator=(const MateriaSource &rhs) {
    for (std::size_t i = 0; i < MateriaSource::kMaxMateria; i += 1) {
        delete materias[i];
        materias[i] = rhs.materias[i] ? rhs.materias[i]->clone() : NULL;
    }
    std::cout
        << Constants::kTextInfo
        << "MateriaSource::operator=(const MateriaSource &rhs)"
        << Constants::kTextReset << std::endl;
    return *this;
}

void        MateriaSource::learnMateria(AMateria* m) {
    if (!m) {
        std::cout
            << Constants::kTextWarning
            << "A MateriaSource tried to learn an imaginary materia..."
            << Constants::kTextReset << std::endl;
        return;
    }
    for (std::size_t i = 0; i < MateriaSource::kMaxMateria; i += 1) {
        if (!materias[i]) {
            materias[i] = m;
            std::cout
                << Constants::kTextInfo
                << "A MateriaSource has learned a " << m->getType() << " type materia into slot #" << i
                << Constants::kTextReset << std::endl;
            return;
        }
    }
    std::cout
        << Constants::kTextWarning
        << "A MateriaSource had tried to learn a " << m->getType() << " type materia, but all slots has been full."
        << Constants::kTextReset << std::endl;
}

AMateria*   MateriaSource::createMateria(std::string const & type) {
    for (std::size_t i = 0; i < MateriaSource::kMaxMateria; i += 1) {
        if (materias[i] && materias[i]->getType() == type) {
            std::cout
                << Constants::kTextInfo
                << "A MateriaSource had cloned a materia type of " << type
                << Constants::kTextReset << std::endl;
            return materias[i]->clone();
        }
    }
    std::cout
        << Constants::kTextWarning
        << "A MateriaSource had tried to clone a materia type of " << type << ", but it hasn't had such materia."
        << Constants::kTextReset << std::endl;
    return NULL;
}
