

#include "Fairy.h"


void Fairy::applyEncounter(Player &player) const {
    Wizard *wizardPlayer = dynamic_cast<Wizard *>(&player);

    if (wizardPlayer != nullptr) {
        //player is Wizard.
        player.heal(10);
        printFairyMessage(true);
        return;
    }

    printFairyMessage(false);

}

std::string Fairy::getName() const {
    return m_name;
}