#ifndef CPP04_EX03_AMATERIA_HPP_
# define CPP04_EX03_AMATERIA_HPP_

# include <iostream>
# include "ICharacter.hpp"

class AMateria {
    protected:
        const std::string type;

    public:
        AMateria(std::string const & type);
        virtual ~AMateria();
        AMateria(const AMateria &from);
        AMateria& operator=(const AMateria &rhs);

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;

        virtual void use(ICharacter& target);
};

#endif
