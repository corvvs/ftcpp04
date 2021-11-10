#ifndef CPP04_EX03_AMATERIA_HPP_
# define CPP04_EX03_AMATERIA_HPP_

# include <iostream>
# include "ICharacter.hpp"
# include "Constants.hpp"

class AMateria {
    protected:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria &from);
        AMateria& operator=(const AMateria &rhs);

        const std::string type;

    public:
        virtual ~AMateria();

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;

        virtual void use(ICharacter& target);
};

#endif
