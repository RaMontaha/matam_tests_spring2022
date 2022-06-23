//
// Created by montaha rayyan on 6/9/22.
//

#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

#include "Player.h"

class Wizard : public Player {
public:

    /*
     * C`tor
     */
    explicit Wizard(const std::string &name) : Player(name) {};

    /*
     * D`tor
     */
    ~Wizard() override = default;

    /*
     * adds double the value of amount to player's HP.
     * note: if the amount is negative or the HP value is max the function doesn't change HP.
     * @param amount
    */
    void heal(int amount) override;

    /*
     * returns Wizard
     */
    std::string getJop()  const override;

private:


};

#endif //EX4_WIZARD_H
