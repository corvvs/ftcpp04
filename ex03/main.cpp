#include "IceMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void    say(const std::string& str) {
    std::cout << std::endl << str << std::endl << std::endl;
}

int main() {
    try {
        IMateriaSource* src = new MateriaSource();
        IceMateria mIce;
        IceMateria *mIceCloned = mIce.clone();


        ICharacter *nop = new Character("nop");
        ICharacter *louis = new Character("louis");
        nop->equip(src->createMateria("ice"));
        nop->use(0, *louis);
        nop->unequip(0);
        src->learnMateria(new IceMateria(mIce));
        nop->equip(mIceCloned);
        nop->use(0, *louis);
        nop->unequip(0);
        nop->use(0, *louis);
        nop->equip(mIceCloned);
        nop->equip(src->createMateria("ice"));
        nop->equip(src->createMateria("meteor"));

        delete nop;
        delete louis;
        delete src;
        say("[ Finish ]");
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
