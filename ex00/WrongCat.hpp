#ifndef CPP04_EX00_WRONGCAT_HPP_
# define CPP04_EX00_WRONGCAT_HPP_

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat &from);
        WrongCat& operator=(const WrongCat &rhs);

        void    makeSound(void) const;
};

#endif
