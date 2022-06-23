//
// Created by montaha rayyan on 6/9/22.
//

#include "Player.h"
#include "../utilities.h"

Player::Player(const std::string name) : m_name(name), m_level(1), m_force(5), m_maxHP(100), m_hp(100), m_coin(10) {}

void Player::levelUp(){
    if (m_level < m_maxHP){
        m_level++;
    }
}

int Player::getLevel() const{
    return m_level;
}

int Player::getHP() const{
    return m_hp;
}


std::string Player::getName() const{
    return m_name;
}


int Player::getCoins() const{
    return m_coin;
}


void Player::buff(int amount){
    if (amount > 0){
        m_force += amount;
    }
}


int Player::getForce() const{
    return m_force;
}


void Player::heal(int amount){
    if (amount <= 0){
        return;
    }
    if ((m_hp + amount) < (this->m_maxHP)){
        m_hp += amount;
    }else{
        m_hp = this->m_maxHP;
    }
}


void Player::damage(int amount){
    if (amount <= 0){
        return;
    }
    if (m_hp > 0){
        m_hp -= amount;
        m_hp = (m_hp > 0) ? m_hp : 0;
    }
}


void Player::damageInForce() {
    if(m_force>0){
        m_force--;
    }
}


bool Player::isKnockedOut() const{
    if (m_hp <= 0){
        return true;
    }
    return false;
}


void Player::addCoins(int amount){
    if (amount > 0){
        m_coin += amount;
    }
}


bool Player::pay(int amount){
    if (m_coin >= amount){
        if (amount > 0){
            m_coin -= amount;
        }
        return true;
    }
    return false;
}


int Player::getAttackStrength() const{
    return (m_level + m_force);
}


std::ostream &operator<<(std::ostream &os, const Player &player){
    printPlayerDetails(os,player.getName(),player.getJop(),player.getLevel(),
                       player.getForce(),player.getHP(),player.getCoins());
    return os;
}


bool isValidName(const std::string &name){
    //check the name length
    if (name.length() > 15){
        printInvalidName();
        return false;
    }

    //check if all letters are english letters
    for (char character: name){
        if (!isalpha(character)){
            printInvalidName();
            return false;
        }
    }
    return true;
}

bool isValidClassName(const std::string &playerClass) {
    if (playerClass != "Wizard" && playerClass != "Fighter" && playerClass != "Rogue"){
        printInvalidClass();
        return false;
    }
    return true;
}