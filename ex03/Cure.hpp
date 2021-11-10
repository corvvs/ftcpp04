#ifndef CPP04_EX03_CURE_HPP_
# define CPP04_EX03_CURE_HPP_

# include <iostream>
# include "AMateria.hpp"
# include "Constants.hpp"

class Cure: public AMateria {
    protected:

    public:
        Cure();
        ~Cure();
        Cure(const Cure &from);
        Cure& operator=(const Cure &rhs);

        Cure* clone() const;

        void use(ICharacter& target);
};

#endif
