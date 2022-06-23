//
// Created by montaha rayyan on 6/15/22.
//
#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const std::string &fileName) {
    printStartGameMessage();
    getDeck(fileName);
    //get the team size
    printEnterTeamSizeMessage();
    do {
        m_numOfActivePlayers = recieveTeamSize();
    } while (!isValidTeamSize(m_numOfActivePlayers));

    //get players details
    getQueueOfPlayers();

    //get the deck from the file

    //start game
    m_round = 0;
}

int recieveTeamSize() {
    std::string input;
    std::cin >> input;
    int teamSize = stoi(input);
    while (teamSize > 6 || teamSize < 2) {
        printInvalidTeamSize();
        std::cin >> input;
        try {
            teamSize = stoi(input);
        }
        catch (const std::string &e) {
            printInvalidTeamSize();
            continue;
        }
    }
    return teamSize;
}

void Mtmchkin::printLeaderBoard() const {

    printLeaderBoardStartMessage();
    int rank = 1;
    for (const std::shared_ptr<Player> &it: m_winners) {
        printPlayerLeaderBoard(rank++, *it);
    }
    for (const std::shared_ptr<Player> &it: m_queueOfActivePlayers) {
        printPlayerLeaderBoard(rank++, *it);
    }
    for (const std::shared_ptr<Player> &it: m_losers) {
        printPlayerLeaderBoard(rank++, *it);
    }
}


void Mtmchkin::playRound() {

    printRoundStartMessage(++m_round);


    int currentTeamSize = m_numOfActivePlayers;

    for (int i = 0; i < currentTeamSize; i++) {
        //get player
        std::shared_ptr<Player> currentPlayer = m_queueOfActivePlayers.front();
        m_queueOfActivePlayers.pop_front();
        printTurnStartMessage(currentPlayer->getName());

        //get card
        std::shared_ptr<Card> currentCard = m_queueOfCards.front();


        //play the card
        currentCard->applyEncounter(*currentPlayer);

        if (currentPlayer->isKnockedOut()) {
            //if the player lost add him to losers.
            m_losers.push_front(currentPlayer);
            m_numOfActivePlayers--;

        } else if (currentPlayer->getLevel() == 10) {
            //if the player won add him to winners.
            m_winners.push_back(currentPlayer);
            m_numOfActivePlayers--;
        } else {
            //else the player still active
            m_queueOfActivePlayers.push_back(currentPlayer);
        }

        //return the card to the end of the deck.
        m_queueOfCards.push(currentCard);
        m_queueOfCards.pop();


        if (isGameOver()) {
            printGameEndMessage();
            break;
        }

    }


}


bool Mtmchkin::isGameOver() const {
    return m_numOfActivePlayers == 0;
}


int Mtmchkin::getNumberOfRounds() const {
    return m_round;
}




//****************** PLAYER HELPER FUNCTIONS ******************//

void Mtmchkin::getQueueOfPlayers() {

    std::string playerName, playerClass;
    for (int i = 0; i < m_numOfActivePlayers;) {
        //get the player name and class.
        getPlayerDetails(playerName, playerClass);

        //create new player according to the class.
        if (playerClass == "Wizard") {

            std::shared_ptr<Player> current(new Wizard(playerName));
            m_queueOfActivePlayers.push_back(current);

        } else if (playerClass == "Fighter") {

            std::shared_ptr<Player> current(new Fighter(playerName));
            m_queueOfActivePlayers.push_back(current);

        } else if (playerClass == "Rogue") {

            std::shared_ptr<Player> current(new Rogue(playerName));
            m_queueOfActivePlayers.push_back(current);
        }

        i++;
    }
}


void Mtmchkin::getPlayerDetails(std::string &playerName, std::string &playerClass) {
    printInsertPlayerMessage();
    do {

        std::cin >> playerName >> playerClass;

    } while (!isValidName(playerName) || !isValidClassName(playerClass));

}


bool Mtmchkin::isValidTeamSize(int size) {
    if (size < 2 || size > 6) {
        printInvalidTeamSize();
        return false;
    }
    return true;
}


//****************** CARD HELPER FUNCTIONS ******************//

void Mtmchkin::getDeck(const std::string &fileName) {
    int line = 0;
    std::string currentCardName;
    std::shared_ptr<Card> current = nullptr;

    //build map
    std::map<std::string, buildFunction> cardMap;
    buildCardMap(cardMap);

    //open file to read only
    std::ifstream source(fileName);
    if (!source) {
        throw DeckFileNotFound();
    }

    //fill the cards queue
    while (getline(source, currentCardName)) {
        removeLineBreaks(currentCardName);

        //create card
        try {
            current = cardMap.at(currentCardName)();
        } catch (std::out_of_range &e) {
            throw DeckFileFormatError(line + 1);
        }


        //add card to the queue
        m_queueOfCards.push(current);
        line++;
    }
    //check the deck size
    if (!isValidDeckSize(line)) {
        throw DeckFileInvalidSize();
    }
}


bool Mtmchkin::isValidDeckSize(int size) {
    if (size < 5) {
        return false;
    }
    return true;
}


std::shared_ptr<Card> buildMerchant() {
    std::shared_ptr<Card> card(new Merchant());
    return card;
}

std::shared_ptr<Card> buildBarfight() {
    std::shared_ptr<Card> card(new Barfight());
    return card;
}

std::shared_ptr<Card> buildDragon() {
    std::shared_ptr<Card> card(new Dragon());
    return card;
}

std::shared_ptr<Card> buildFairy() {
    std::shared_ptr<Card> card(new Fairy());
    return card;
}

std::shared_ptr<Card> buildGoblin() {

    std::shared_ptr<Card> card(new Goblin());
    return card;
}

std::shared_ptr<Card> buildPitfall() {
    std::shared_ptr<Card> card(new Pitfall());
    return card;
}

std::shared_ptr<Card> buildTreasure() {
    std::shared_ptr<Card> card(new Treasure());
    return card;
}

std::shared_ptr<Card> buildVampire() {
    std::shared_ptr<Card> card(new Vampire());
    return card;
}

void buildCardMap(std::map<std::string, buildFunction> &mapStringToCardName) {
    mapStringToCardName.emplace("Vampire", buildVampire);
    mapStringToCardName.emplace("Barfight", buildBarfight);
    mapStringToCardName.emplace("Dragon", buildDragon);
    mapStringToCardName.emplace("Fairy", buildFairy);
    mapStringToCardName.emplace("Goblin", buildGoblin);
    mapStringToCardName.emplace("Merchant", buildMerchant);
    mapStringToCardName.emplace("Pitfall", buildPitfall);
    mapStringToCardName.emplace("Treasure", buildTreasure);

}

void Mtmchkin::removeLineBreaks(std::string &str) {

    if (!str.empty() && str[str.length() - 1] == '\n') {
        str.erase(str.length() - 1);
    }
    if (!str.empty() && str[str.length() - 1] == '\r') {
        str.erase(str.length() - 1);
    }
}