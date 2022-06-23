//
// Created by montaha rayyan on 6/9/22.
//

#include "Wizard.h"


void Wizard::heal(int amount){
    Player::heal(2*amount);
}


std::string Wizard::getJop() const {
    return "Wizard";
}