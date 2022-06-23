
#include "Card.h"
#include <iostream>
#include <string>

Card::Card(std::string name) {
    if (!isValidType(name)) {
        throw InvalidType();
    }
    m_name = name;
}



bool Card::isValidType(const std::string &cardName) {
    if (cardName.length() > 15) {
        return false;
    }

    //check if all letters are english letters
    for (char character: cardName) {
        if (!isalpha(character)) {
            return false;
        }
    }
    return true;
}

void Card::printInfo(std::ostream &os) const {
    printCardDetails(os, this->getName());
}

std::ostream &operator<<(std::ostream &os, const Card &card){
    card.printInfo(os);
    printEndOfCardDetails(os);
    return os;
}