//
// Created by montaha rayyan on 6/9/22.
//

#include "Rogue.h"


void Rogue::addCoins(int amount) {
    Player::addCoins(2 * amount);
}



std::string Rogue::getJop() const {
    return "Rogue";
}



