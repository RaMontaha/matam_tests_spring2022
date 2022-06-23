
#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Battle.h"

class Dragon : public Battle {
public:
    /*
     * c`tor
     */
    Dragon() : Battle("Dragon") {
        m_force = 25;
        m_hpLossOnDefeat = 0; // loses all the hp(real usage in BATTLE)
        m_loot = 1000;
    };

    /*
     * d`tor
     */
    ~Dragon() override = default;

    /*
     * copy c`tor
     */
    Dragon(Dragon &card) = default;

    /*
     * if the player wins the player goes a levelUp and gets the loot of the card.
     * if lthe player loses the player loses health points as in the card.
     * @param player - The player.
     * @return
     *      void
     */
    void applyEncounter(Player &player) const override;

    /*
     * returns a copy of the card name.
     */
    std::string getName() const override;

    /*
     * returns Dragon card force.
     */
    int getForce() const override;

    /*
     * returns Dragon card loot.
     */
    int getLoot() const override;

    /*
     * returns number of hp player lose on defeat.
     */
    int getHpLossOnDefeat() const override;

    /*
     * flag to Dragon card.
     */
    bool isDragon() const  override;
};

#endif // EX4_DRAGON_H