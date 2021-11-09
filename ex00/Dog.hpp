#ifndef CPP04_EX00_DOG_HPP_
# define CPP04_EX00_DOG_HPP_

# include "Animal.hpp"

class Dog: public Animal {
    public:
        Dog();
        ~Dog();
        Dog(const Dog &from);
        Dog& operator=(const Dog &rhs);

        void    makeSound(void) const;
};

#endif
