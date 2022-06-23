#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"

class Fairy : public Card {
public:
    /*
     * c`tor
     */
    Fairy() : Card("Fairy") {};

    /*
     * d`tor
     */
    ~Fairy() override = default;

    /*
     * copy c`tor
     */
    Fairy(Fairy &fairy) = default;

    /*
     * returns a copy of the card name.
     */
    std::string getName() const override;


    /*
     * Handling the player's applyEncounter with the card:
     *
     * It will increase the player's life points by 10 points only if the player is a Wizard.
     * (because of the special act of the wizard player  it will actually increase the health points by 20).
     *
     * @param player - The player.
     * @return
     *      void
     */
    void applyEncounter(Player &player) const override;


};
#endif // EX4_FAIRY_H
