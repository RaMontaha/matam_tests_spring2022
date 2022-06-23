#include "Dragon.h"

void Dragon::applyEncounter(Player &player) const {
    if (player.getAttackStrength() >= m_force) {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),m_name);
    } else {
        player.damage(player.getHP());
        printLossBattle(player.getName(), m_name);
    }
}

std::string Dragon::getName() const {
    return m_name;
}


int Dragon::getForce() const {
    return m_force;
}

int Dragon::getLoot() const {
    return m_loot;
}

int Dragon::getHpLossOnDefeat() const {
    return m_hpLossOnDefeat;
}

bool Dragon::isDragon() const {
    return true;
}