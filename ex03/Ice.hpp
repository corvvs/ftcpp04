#ifndef CPP04_EX03_ICE_HPP_
# define CPP04_EX03_ICE_HPP_

# include <iostream>
# include "AMateria.hpp"
# include "Constants.hpp"

class Ice: public AMateria {
    protected:

    public:
        Ice();
        virtual ~Ice();
        Ice(const Ice &from);
        Ice& operator=(const Ice &rhs);

        Ice* clone() const;

        void use(ICharacter& target);
};

#endif
