#include "Treasure.h"

void Treasure::applyEncounter(Player &player) const{
    player.addCoins(10);
    printTreasureMessage();
}

std::string Treasure::getName() const {
    return m_name;
}