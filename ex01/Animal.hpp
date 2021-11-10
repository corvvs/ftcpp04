#ifndef CPP04_EX01_ANIMAL_HPP_
# define CPP04_EX01_ANIMAL_HPP_

# include <iostream>
# include "Constants.hpp"

class Animal {
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        Animal(const Animal &from);
        Animal& operator=(const Animal &rhs);

        const std::string&  getType(void) const;
        virtual void        makeSound(void) const;
        virtual void        showIdeas(void) const;

    protected:
        std::string type;
};

#endif
