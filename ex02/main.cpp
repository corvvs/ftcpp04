#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void    say(const std::string& str) {
    std::cout << std::endl << str << std::endl << std::endl;
}

int main() {
    try {
        // Animal a; // error: variable type 'Animal' is an abstract class
        // Animal *ap = new Animal(); // allocating an object of abstract class type 'Animal'

        const std::size_t N = 4;
        say("[ Create Array of Animals ]");
        Animal* animals[N];

        say("[ Fill Array by Dogs and Cats ]");
        for (std::size_t i = 0; i < N; i += 1) {
            if (i < N / 2) {
                animals[i] = new Dog();
            } else {
                animals[i] = new Cat();
            }
        }

        say("[ Show Original Ideas ]");
        animals[0]->showIdeas();
        animals[N / 2]->showIdeas();

        say("[ Copy a Dog and a Cat ]");
        Dog copyDog(*(dynamic_cast<Dog *>(animals[0])));
        Cat copyCat(*(dynamic_cast<Cat *>(animals[N / 2])));

        say("[ Delete Animals on Heap ]");
        for (std::size_t i = 0; i < N; i += 1) {
            delete animals[i];
        }

        say("[ Show Copied Ideas ]");
        copyDog.showIdeas();
        copyCat.showIdeas();

        say("[ Leak with assignation ]");
        Dog d;
        Dog f;
        d = f;
        Cat g;
        Cat h;
        g = h;

        say("[ Finish ]");
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
