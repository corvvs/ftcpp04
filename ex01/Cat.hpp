#ifndef CPP04_EX01_CAT_HPP_
# define CPP04_EX01_CAT_HPP_

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
    public:
        Cat();
        virtual ~Cat();
        Cat(const Cat &from);
        Cat& operator=(const Cat &rhs);

        void            makeSound(void) const;
        const Brain*    getBrain(void) const;
        void            showIdeas(void) const;

    private:
        Brain               *brain_;
};

#endif
