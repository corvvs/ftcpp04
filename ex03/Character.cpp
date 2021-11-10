#include "Character.hpp"

Character::Character(): name_("<nameless>") {
    for (std::size_t i = 0; i < Character::kMaxMateria; i += 1) {
        materias[i] = NULL;
    }
    std::cout
        << Constants::kTextInfo
        << "Character::Character()"
        << Constants::kTextReset << std::endl;
}

Character::~Character() {
    for (std::size_t i = 0; i < Character::kMaxMateria; i += 1) {
        if (materias[i]) {
            delete materias[i];
        }
    }
    std::cout
        << Constants::kTextInfo
        << "Character::~Character()"
        << Constants::kTextReset << std::endl;
}

Character::Character(std::string const & name): name_(name) {
    for (std::size_t i = 0; i < Character::kMaxMateria; i += 1) {
        materias[i] = NULL;
    }
    std::cout
        << Constants::kTextInfo
        << "Character::Character(std::string const & name)"
        << Constants::kTextReset << std::endl;
}

Character::Character(const Character& from): name_(from.name_) {
    for (std::size_t i = 0; i < Character::kMaxMateria; i += 1) {
        materias[i] = from.materias[i] ? from.materias[i]->clone() : NULL;
    }
    std::cout
        << Constants::kTextInfo
        << "Character::Character(const Character& from)"
        << Constants::kTextReset << std::endl;
}

Character& Character::operator=(const Character &rhs) {
    for (std::size_t i = 0; i < Character::kMaxMateria; i += 1) {
        if (materias[i]) {
            delete materias[i];
        }
        materias[i] = rhs.materias[i] ? rhs.materias[i]->clone() : NULL;
    }
    std::cout
        << Constants::kTextInfo
        << "Character::operator=(const Character &rhs)"
        << Constants::kTextReset << std::endl;
    return *this;
}

std::string const & Character::getName() const {
    return name_;
} 

void    Character::equip(AMateria* m) {
    // The Character possesses an inventory of 4 Materia at most, empty at the start. He’ll equip the Materia in slots 0 to 3, in this order.
    if (!m) {
        std::cout
            << Constants::kTextWarning
            << name_ << " tried to equip an imaginary materia..."
            << Constants::kTextReset << std::endl;
        return;
    }
    for (std::size_t i = 0; i < Character::kMaxMateria; i += 1) {
        if (!materias[i]) {
            materias[i] = m;
            std::cout
                << Constants::kTextInfo
                << name_ << " equipped a " << m->getType() << " type materia in slot #" << i
                << Constants::kTextReset << std::endl;
            return;
        }
    }
    // no vacant slot.
    // > In case we try to equip a Materia in a full inventory, or use/unequip a nonexistent Materia, don’t do a thing.
    std::cout
        << Constants::kTextWarning
        << name_ << " tried to equip a " << m->getType() << " type materia, but no vacant slot."
        << Constants::kTextReset << std::endl;
}

void    Character::unequip(int idx) {
    // > In case we try to equip a Materia in a full inventory, or use/unequip a nonexistent Materia, don’t do a thing.
    if (idx < 0 || (int)Character::kMaxMateria <= idx) {
        // out of range
        std::cout
            << Constants::kTextWarning
            << name_ << " tried to unequip for slot #" << idx << ", but it's a imaginary."
            << Constants::kTextReset << std::endl;
        return;
    }
    if (!materias[idx]) {
        // specified vacant slot
        std::cout
            << Constants::kTextWarning
            << name_ << " tried to unequip for slot #" << idx << ", but it's already vacant."
            << Constants::kTextReset << std::endl;
        return;
    }
    // > The unequip method must NOT delete Materia!
    materias[idx] = NULL;
}

void    Character::use(int idx, ICharacter& target) {
    // > In case we try to equip a Materia in a full inventory, or use/unequip a nonexistent Materia, don’t do a thing.
    if (idx < 0 || (int)Character::kMaxMateria <= idx) {
        // out of range
        std::cout
            << Constants::kTextWarning
            << name_ << " tried to use a materia in slot #" << idx << ", but it's a imaginary."
            << Constants::kTextReset << std::endl;
        return;
    }
    if (!materias[idx]) {
        // specified vacant slot
        std::cout
            << Constants::kTextWarning
            << name_ << " tried to use a materia in slot #" << idx << ", but it's vacant."
            << Constants::kTextReset << std::endl;
        return;
    }
    materias[idx]->use(target);
}
