#include "IceMateria.hpp"
#include "Character.hpp"

void    say(const std::string& str) {
    std::cout << std::endl << str << std::endl << std::endl;
}

int main() {
    try {
        IceMateria mIce;
        IceMateria *mIceCloned = mIce.clone();

        ICharacter *nop = new Character("nop");
        ICharacter *louis = new Character("louis");
        nop->use(0, *louis);
        nop->unequip(0);
        nop->equip(mIceCloned);
        nop->use(0, *louis);
        nop->unequip(0);
        nop->use(0, *louis);
        nop->equip(mIceCloned);

        delete nop;
        delete louis;
        say("[ Finish ]");
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
