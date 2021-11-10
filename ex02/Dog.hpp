#ifndef CPP04_EX02_DOG_HPP_
# define CPP04_EX02_DOG_HPP_

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
    public:
        Dog();
        ~Dog();
        Dog(const Dog &from);
        Dog& operator=(const Dog &rhs);

        void            makeSound(void) const;
        const Brain*    getBrain(void) const;
        void            showIdeas(void) const;

    private:
        Brain               *brain_;
};

#endif
