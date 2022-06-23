//
// Created by montaha rayyan on 6/9/22.
//

#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

#include "Player.h"


class Rogue : public Player {
public:
    /*
     * C`tor
     */
    explicit Rogue(const std::string &name) : Player(name) {};

    /*
     * D`tor
     */
    ~Rogue() override = default;

    /*
    * increases the coins by double the amount's value.
    * note: if the amount is negative the function doesn't change the coins.
    * @param amount
    */
    void addCoins(int amount) override;

    /*
     * returns Rogue
     */
    std::string getJop()  const override;



private:


};

#endif //EX4_ROGUE_H
