#include "Battle.h"


void Battle::applyEncounter(Player &player) const
{
    if (player.getAttackStrength() >= m_force)
    {
        player.levelUp();
        player.addCoins(m_loot);
        printWinBattle(player.getName(),m_name);
    }
    else
    {
        if(this->isVampire()){
            player.damageInForce();
        }
        player.damage(m_hpLossOnDefeat);
        printLossBattle(player.getName(),m_name);
    }
}

void Battle::printInfo(std::ostream &os) const {
    printCardDetails(os, this->getName());
    printMonsterDetails(os, this->getForce(), this->getHpLossOnDefeat(), this->getLoot(), this->isDragon());
    }
