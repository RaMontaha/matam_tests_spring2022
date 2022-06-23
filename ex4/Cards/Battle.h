
#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H

#include "Card.h"
#include "../utilities.h"
#include <iostream>

class Battle : public Card{
public:
    /*
     * c`tor
     */
    Battle():Card("Battle"){};

    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
     */
    explicit Battle(std::string battle):Card(battle){};

    /*
     * d`tor
     */
    ~Battle() override = default;

    /*
     * copy c`tor
     */
    Battle(Battle &card) = default;

    /*
     * returns card force.
     */
    virtual int getForce() const = 0;

    /*
     * returns card loot.
     */
    virtual int getLoot() const = 0;

    /*
     * returns number of hp player lose on defeat.
     */
    virtual int getHpLossOnDefeat() const = 0;

    /*
     * flag to Dragon Card
     */
    virtual bool isDragon() const {return false;};

    /*
     * flag to Vampire card
     */
    virtual bool isVampire()const {return false;};

    /*
     * if the player wins the player goes a levelUp and gets the loot of the card.
     * if the player loses the player loses health points as in the card.
     * @param player - The player.
     * @return
     *      void
     */
    void applyEncounter(Player &player) const override;

    void printInfo(std::ostream &os) const override;

protected:
    int m_force;
    int m_loot;
    int m_hpLossOnDefeat;
};
#endif // EX4_BATTLE_H