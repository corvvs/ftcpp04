#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void    say(const std::string& str) {
    std::cout << std::endl << str << std::endl << std::endl;
}

int main() {
    {
        say("[ Correct Case ]");

        say("[ Construct Objects ]");
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        say("[ Types ]");
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        say("[ Sounds ]");
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();

        say("[ Delete Objects ]");
        delete meta;
        delete j;
        delete i;
    }
    {
        say("[ Wrong Case ]");

        say("[ Construct Objects ]");
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();

        say("[ Types ]");
        std::cout << i->getType() << " " << std::endl;

        say("[ Sounds ]");
        i->makeSound();
        meta->makeSound();

        say("[ Delete Objects ]");
        delete meta;
        delete i;
    }
}
