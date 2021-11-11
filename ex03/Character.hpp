#ifndef CPP04_EX03_CHARACTER_HPP_
# define CPP04_EX03_CHARACTER_HPP_

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Constants.hpp"

class Character: public ICharacter {
    private:
        static const std::size_t    kMaxMateria = 4;
        const std::string   name_;
        AMateria    *materias[Character::kMaxMateria];

    public:
        Character();
        virtual ~Character();
        Character(std::string const & name);
        Character(const Character& from);
        Character&  operator=(const Character &rhs);

        std::string const & getName() const;
        void    equip(AMateria* m);
        void    unequip(int idx);
        void    use(int idx, ICharacter& target);
};

#endif
