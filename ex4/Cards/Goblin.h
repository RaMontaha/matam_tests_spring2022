
#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Battle.h"

class Goblin : public Battle {
public:
    /*
     * c`tor
     */
    Goblin();

    /*
     * d`tor
     */
    ~Goblin() override = default;
    
    /*
     * copy c`tor
     */
    Goblin(Goblin &card) = default;
    
    /*
     * returns a copy of the card name.
     */
    std::string getName() const override;
    
    /*
     * returns Goblin card force.
     */
    int getForce() const override;

    /*
     * returns Goblin card loot.
     */
    int getLoot() const override;

    /*
     * returns number of hp player lose on defeat.
     */
    int getHpLossOnDefeat() const override;    
};

#endif // EX4_GOBLIN_H