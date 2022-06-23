

#include "Barfight.h"


void Barfight::applyEncounter(Player &player) const{
    bool isFighter = true;

    Fighter* fighterPlayer = dynamic_cast<Fighter*>(&player);

    if(fighterPlayer== nullptr){
        //player is not Fighter.
        player.damage(10);
        isFighter= false;
    }

    printBarfightMessage(isFighter);
}

std::string Barfight::getName() const {
    return m_name;
}
