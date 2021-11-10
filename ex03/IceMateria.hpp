#ifndef CPP04_EX03_ICEMATERIA_HPP_
# define CPP04_EX03_ICEMATERIA_HPP_

# include <iostream>
# include "AMateria.hpp"

class IceMateria: public AMateria {
    protected:

    public:
        IceMateria();
        ~IceMateria();
        IceMateria(const IceMateria &from);
        IceMateria& operator=(const IceMateria &rhs);

        IceMateria* clone() const;

        void use(ICharacter& target);
};

#endif
