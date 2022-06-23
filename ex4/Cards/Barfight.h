
#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"


class Barfight : public Card {
public:
    /*
     * c`tor
     */
    Barfight() : Card("Barfight") {};

    /*
     * d`tor
     */
    ~Barfight() override = default;

    /*
     * copy c`tor
     */
    Barfight(Barfight &card) = default;

    /*
     * returns a copy of the card name.
     */
    std::string getName() const override;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * decreases the health points by 10, except for Fighter it does nothing.
     *
     * @param player - The player.
     * @return
     *      void
     */
    void applyEncounter(Player &player) const override;

};

#endif //EX4_BARFIGHT_H
