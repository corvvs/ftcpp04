#include "Character.hpp"

Character::Character(): name_("<nameless>") {
    for (std::size_t i = 0; i < Character::kMaxMateria; i += 1) {
        materias[i] = NULL;
    }
}

Character::~Character() {
    for (std::size_t i = 0; i < Character::kMaxMateria; i += 1) {
        if (materias[i]) {
            delete materias[i];
        }
    }
}

Character::Character(std::string const & name): name_(name) {
    for (std::size_t i = 0; i < Character::kMaxMateria; i += 1) {
        materias[i] = NULL;
    }
}

Character::Character(const Character& from): name_(from.name_) {
    for (std::size_t i = 0; i < Character::kMaxMateria; i += 1) {
        materias[i] = from.materias[i] ? from.materias[i]->clone() : NULL;
    }
}

Character& Character::operator=(const Character &rhs) {
    for (std::size_t i = 0; i < Character::kMaxMateria; i += 1) {
        if (materias[i]) {
            delete materias[i];
        }
        materias[i] = rhs.materias[i] ? rhs.materias[i]->clone() : NULL;
    }
    return *this;
}

std::string const & Character::getName() const {
    return name_;
} 

void    Character::equip(AMateria* m) {
    // The Character possesses an inventory of 4 Materia at most, empty at the start. He’ll equip the Materia in slots 0 to 3, in this order.
    for (std::size_t i = 0; i < Character::kMaxMateria; i += 1) {
        if (!materias[i]) {
            materias[i] = m;
            return;
        }
    }
    // no vacant slot.
    // > In case we try to equip a Materia in a full inventory, or use/unequip a nonexistent Materia, don’t do a thing.
}

void    Character::unequip(int idx) {
    // > In case we try to equip a Materia in a full inventory, or use/unequip a nonexistent Materia, don’t do a thing.
    if (idx < 0 || (int)Character::kMaxMateria <= idx) {
        // out of range
        return;
    }
    if (!materias[idx]) {
        // specified vacant slot
        return;
    }
    // > The unequip method must NOT delete Materia!
    materias[idx] = NULL;
}

void    Character::use(int idx, ICharacter& target) {
    // > In case we try to equip a Materia in a full inventory, or use/unequip a nonexistent Materia, don’t do a thing.
    if (idx < 0 || (int)Character::kMaxMateria <= idx) {
        // out of range
        return;
    }
    if (!materias[idx]) {
        // specified vacant slot
        return;
    }
    materias[idx]->use(target);
}
