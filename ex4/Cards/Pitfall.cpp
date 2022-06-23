

#include "Pitfall.h"


void Pitfall::applyEncounter(Player &player) const {
    bool isRogue = true;

    Rogue* roguePlayer = dynamic_cast<Rogue*> (&player);

    if(roguePlayer== nullptr){
        //player is not Rogue.
        player.damage(10);
        isRogue= false;
    }

    printPitfallMessage(isRogue);

}

std::string Pitfall::getName() const {
    return m_name;
}