#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

class Merchant : public Card{
public:
    /*
     * c`tor
     */
    Merchant() : Card("Merchant"){};

    /*
     * d`tor
     */
    ~Merchant() override = default;

    /*
     * copy c`tor
     */
    Merchant(Merchant &card) = default;

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
#endif // EX4_MERCHANT_H

