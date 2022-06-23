
#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"
#include <memory>
#include <iostream>

class Pitfall : public Card {
public:
    /*
     * c`tor
     */
    Pitfall() : Card("Pitfall") {};

    /*
     * d`tor
     */
    ~Pitfall() override = default;

    /*
     * copy c`tor
     */
    Pitfall(Pitfall &card) = default;

    /*
     * returns a copy of the card name.
     */
    std::string getName() const override;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * decreases the health points by 10, except the Rouge it does nothing.
     *
     * @param player - The player.
     * @return
     *      void
     */
    void applyEncounter(Player &player) const override;

};
#endif // EX4_PITFALL_H
