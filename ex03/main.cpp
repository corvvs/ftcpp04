#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void    say(const std::string& str) {
    std::cout << std::endl << str << std::endl << std::endl;
}

int main() {
    try {
        say("[ Deploy Ice Materias ]");
        IMateriaSource* src = new MateriaSource();

        Ice mIce;
        AMateria *mIceCloned = mIce.clone();
        Ice mIceCloned2;
        mIceCloned2 = *(dynamic_cast<Ice *>(mIceCloned));

        say("[ Characters ]");

        ICharacter *nop = new Character("nop");
        ICharacter *louis = new Character("louis");
        Character nameless;
        nop->equip(src->createMateria("ice"));
        nop->use(0, *louis);
        nop->unequip(0);
        src->learnMateria(new Ice(mIce));
        nop->equip(mIceCloned);
        nop->use(0, *louis);
        nop->unequip(0);
        nop->use(0, *louis);
        nop->equip(mIceCloned);

        say("[ Clone MateriaSource ]");

        IMateriaSource *src2 = new MateriaSource(*dynamic_cast<MateriaSource *>(src));
        src->learnMateria(NULL);
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        MateriaSource src3;
        src3 = *dynamic_cast<MateriaSource *>(src);

        say("[ Equip and Use ]");

        nop->equip(NULL);
        nop->equip(src->createMateria("ice"));
        nop->equip(src->createMateria("meteor"));
        nop->equip(src->createMateria("cure"));
        nop->equip(src->createMateria("cure"));
        AMateria *rest = src->createMateria("cure");
        nop->equip(rest);
        delete rest;
        nop->use(-1, *louis);
        nop->use(0, *louis);
        nop->use(1, *louis);
        nop->use(2, *louis);
        nop->use(3, *louis);
        nop->use(4, *louis);

        say("[ assign <louis> to <nameless> ]");

        louis->equip(src->createMateria("cure"));
        nameless.use(0, *nop);
        nameless = *(dynamic_cast<Character *>(louis));
        nameless.equip(src->createMateria("ice"));
        nameless.use(0, *nop);

        say("[ Delete Explicitly ]");

        delete nop;
        delete louis;
        delete src;
        delete src2;

        say("[ Finish ]");
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
