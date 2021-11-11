#ifndef CPP04_EX00_CAT_HPP_
# define CPP04_EX00_CAT_HPP_

# include "Animal.hpp"

class Cat: public Animal {
    public:
        Cat();
        virtual ~Cat();
        Cat(const Cat &from);
        Cat& operator=(const Cat &rhs);

        void    makeSound(void) const;
};

#endif
