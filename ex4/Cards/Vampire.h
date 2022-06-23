
#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Battle.h"
#include <memory>
#include <iostream>


class Vampire : public Battle {
public:
    /*
     * c`tor
     */
    Vampire();

    /*
     * d`tor
     */
    ~Vampire() override = default;

    /*
     * copy c`tor
     */
    Vampire(Vampire &card) = default;

    /*
     * returns a copy of the card name.
     */
    std::string getName() const override;

    /*
     * returns Vampire card force.
     */
    int getForce() const override;

    /*
     * returns Vampire card loot.
     */
    int getLoot() const override;

    /*
     * returns number of hp player lose on defeat.
     */
    int getHpLossOnDefeat() const override;

    bool isVampire() const override { return true; };
};

#endif // EX4_VAMPIRE_H