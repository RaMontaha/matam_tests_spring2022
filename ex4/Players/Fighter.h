//
// Created by montaha rayyan on 6/9/22.
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"

class Fighter : public Player {
public:
    /*
     * C`tor
     */
    explicit Fighter(const std::string &name) : Player(name) {};

    /*
     * D`tor
     */
    ~Fighter() override = default;

    /*
     * attack strength is defined to be 2*level + force.
     * @return the attack strength
    */
    int getAttackStrength() const override;

    /*
    * returns Fighter
    */
    std::string getJop()  const override;

private:


};

#endif //EX4_FIGHTER_H
