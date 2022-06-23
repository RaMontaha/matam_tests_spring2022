//
// Created by montaha rayyan on 6/9/22.
//

#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <iostream>
#include <cstring>
#include "../Exception.h"


class Player {

public:
    /*
     * C`tor of Player Class
     * Player starts at level(1), with 10 coins, 5 power, and life points full, i.e. equal to maximum life points (maxHP) which is 100 for all players.
     *
     *
     * @param inputName - Player's name
     * note: player's name must be consists only of lowercase and uppercase English letters and without spaces and does not exceed 15 letters.
     */
    explicit Player(const std::string name);

    /*
     * copy C`tor.
     * @param player
     */
    Player(const Player &player) = default;

    /*
     * default C`tor
     */
    Player() = default;

    /*
     * d`tor
     */
    virtual ~Player() = default;

    /*
     * increase the level value by one.
     */
    void levelUp();

    /*
     * @return player's level.
     */
    int getLevel() const;

    /*
     * @return player's name.
     */
    std::string getName() const;

    /*
     * @return player's health points.
     */
    int getHP() const;

    /*
     * @return player's force.
     */
    int getForce() const;

    /*
     * @return player's health points.
     */
    int getCoins() const;

    /*
     * adds the value of the amount to player's force.
     * note: if the amount is negative the function doesn't change the force.
     * @param amount
     */
    void buff(int amount);

    /*
     * adds the value of the amount to player's HP.
     * note: if the amount is negative or the HP value is max the function doesn't change HP.
     * @param amount
     */
    virtual void heal(int amount);

    /*
     * reduces HP by the amount's value.
     * note: hp can be reduced until it's zero, if the amount is negative the function doesn't change HP.
     * @param amount
     */
    void damage(int amount);

    /*
     * reduces player force by one.
     */
    void damageInForce();
    /*
     * checks if the players is knocked out.
     * @return true if the HP = 0.
     */
    bool isKnockedOut() const;


    /*
     * do payment; reduces the number of coins by the amount's value.
     * note: if the there is no enough coins or the amount is negative the function doesn't change the number of coins.
     * @param amount
     * @return true if the payment is succeeded or the amount is negative, false if the payment failed.
     */
    bool pay(int amount);

    /*
     * attack strength is defined to be level+force.
     * @return the attack strength
     */
    virtual int getAttackStrength() const;

    /*
     * increases the coins by the amount's value.
     * note: if the amount is negative the function doesn't change the coins.
     * @param amount
     */
    virtual void addCoins(int amount);

    /*
     * returns player jop.
     */
    virtual std::string getJop() const = 0;


    friend std::ostream &operator<<(std::ostream &os, const Player &player);


protected:
    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_hp;
    int m_coin;
};

/*
 * returns true if the name is valid.
 */
bool isValidName(const std::string &name);

/*
 * returns true if the playerClass name is valid.
 */
bool isValidClassName(const std::string &playerClass);

#endif //EX4_PLAYER_H
