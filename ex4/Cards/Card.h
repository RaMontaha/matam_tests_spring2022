#ifndef EX4_CARD_H
#define EX4_CARD_H

#include "../Players/Player.h"
#include "../Players/Rogue.h"
#include "../Players/Fighter.h"
#include "../Players/Wizard.h"
#include "../utilities.h"
#include <map>
#include <string>
#include <iostream>

class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
     */
    explicit Card(std::string name);

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
     */
    virtual void applyEncounter(Player &player) const = 0;

    /*
     * Here we are explicitly telling the compiler to use the default methods
     */
    Card(const Card &) = default;

    /*
     * default d`tor
     */
    virtual ~Card() = default;

    /*
     * returns true if the type length is under 15 characters.
     */
    static bool isValidType(const std::string &cardName);

    /*
     * returns a copy of the card name.
     */
    virtual std::string getName() const = 0;

    /*
     * print card details.
     */
    virtual void printInfo(std::ostream &os) const ;

    Card &operator=(const Card &other) = default;

    friend std::ostream &operator<<(std::ostream &os, const Card &card);

protected:
    std::string m_name;
};

#endif // EX4_CARD_H
