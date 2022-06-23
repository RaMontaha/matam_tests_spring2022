//
// Created by montaha rayyan on 6/9/22.
//

#include "Fighter.h"



int Fighter::getAttackStrength() const {
    return (2 * m_force + m_level);
}


std::string Fighter::getJop() const {
    return "Fighter";
}
