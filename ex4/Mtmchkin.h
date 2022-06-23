#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <queue>
#include <map>
#include <iostream>
#include <deque>
#include <memory>
#include <fstream>
#include "Cards/Card.h"
#include "Cards/Pitfall.h"
#include "Cards/Fairy.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Battle.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Players/Player.h"
#include "utilities.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"

typedef std::shared_ptr<Card> (*buildFunction)();

class Mtmchkin{

public:
    /*
     * C'tor of Mtmchkin class
     *
     * @param filename - a file which contains the cards of the deck.
     * @return
     *      A new instance of Mtmchkin.
     */
    explicit Mtmchkin(const std::string &fileName);

    /*
     * Play the next Round of the game - according to the instruction in the exercise document.
     *
     * @return
     *      void
     */
    void playRound();

    /*
     * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
     *
     * @return
     *      void
     */
    void printLeaderBoard() const;

    /*
     *  Checks if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isGameOver() const;

    /*
     *  Returns the number of rounds played.
     *
     *  @return
     *          int - number of rounds played
     */
    int getNumberOfRounds() const;

private:
    std::deque<std::shared_ptr<Player>> m_queueOfActivePlayers;
    std::deque<std::shared_ptr<Player>> m_winners;
    std::deque<std::shared_ptr<Player>> m_losers;
    std::queue<std::shared_ptr<Card>> m_queueOfCards;
    int m_numOfActivePlayers;
    int m_round;

    /*
     * builds the players queue.
     */
    void getQueueOfPlayers();

    /*
     * gets valid player name and class.
     */
    static void getPlayerDetails(std::string &playerName, std::string &playerClass);

    /*
     * returns true if the team size between 2 and 6.
     */
    static bool isValidTeamSize(int size);

    /*
     * builds the cards queue.
     */
    void getDeck(const std::string &fileName);

    /*
     * returns true if the deck size is minimum 5.
     */
    static bool isValidDeckSize(int size);

    /*
     * removes line breaks from the end of string (\n,\r,\r\n).
     */
    void static removeLineBreaks(std::string &str);
};

//************ CARDS BUILD FUNCTIONS  ******************/

int recieveTeamSize() ;


void buildCardMap(std::map<std::string, buildFunction> &mapStringToCardName);

std::shared_ptr<Card> buildMerchant();

std::shared_ptr<Card> buildBarfight();

std::shared_ptr<Card> buildDragon();

std::shared_ptr<Card> buildFairy();

std::shared_ptr<Card> buildGoblin();

std::shared_ptr<Card> buildPitfall();

std::shared_ptr<Card> buildTreasure();

std::shared_ptr<Card> buildVampire();



#endif /* MTMCHKIN_H_ */