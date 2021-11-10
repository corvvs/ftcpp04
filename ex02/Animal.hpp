#ifndef CPP04_EX02_ANIMAL_HPP_
# define CPP04_EX02_ANIMAL_HPP_

# include <iostream>

class Animal {
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        Animal(const Animal &from);
        Animal& operator=(const Animal &rhs);

        const std::string&  getType(void) const;
        virtual void        makeSound(void) const = 0;
        virtual void        showIdeas(void) const = 0;

    protected:
        std::string type;
};

#endif
