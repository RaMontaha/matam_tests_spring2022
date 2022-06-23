#include "Goblin.h"

Goblin::Goblin() : Battle("Goblin") {
    m_force = 6;
    m_hpLossOnDefeat = 10;
    m_loot = 2;
}

std::string Goblin::getName() const {
    return m_name;
}

int Goblin::getForce() const {
    return m_force;
}

int Goblin::getLoot() const {
    return m_loot;
}

int Goblin::getHpLossOnDefeat() const {
    return m_hpLossOnDefeat;
}