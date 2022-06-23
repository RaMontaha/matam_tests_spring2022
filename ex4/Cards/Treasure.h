
#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"
#include <memory>
#include <iostream>
#include <deque>
#include <fstream>
#include <queue>

class Treasure : public Card {
public:
    /*
     * c`tor
     */
    Treasure() : Card("Treasure") {};

    /*
     * d`tor
     */
    ~Treasure() override = default;

    /*
     * copy c`tor
     */
    Treasure(Treasure &card) = default;

    /*
     * returns a copy of the card name.
     */
    std::string getName() const override;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
     */
    void applyEncounter(Player &player) const override;
};
#endif // EX4_TREASURE_H
