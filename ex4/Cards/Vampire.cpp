#include "Vampire.h"

Vampire::Vampire() : Battle("Vampire") {
    m_force = 10;
    m_hpLossOnDefeat = 10;
    m_loot = 2;
}

std::string Vampire::getName() const {
    return m_name;
}

int Vampire::getForce() const {
    return m_force;
}

int Vampire::getLoot() const {
    return m_loot;
}

int Vampire::getHpLossOnDefeat() const {
    return m_hpLossOnDefeat;
}