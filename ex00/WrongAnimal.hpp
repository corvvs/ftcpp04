#ifndef CPP04_EX00_WRONGANIMAL_HPP_
# define CPP04_EX00_WRONGANIMAL_HPP_

# include <iostream>

class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        virtual ~WrongAnimal();
        WrongAnimal(const WrongAnimal &from);
        WrongAnimal& operator=(const WrongAnimal &rhs);

        const std::string&  getType(void) const;
        void                makeSound(void) const;

    protected:
        std::string type;
};

#endif
