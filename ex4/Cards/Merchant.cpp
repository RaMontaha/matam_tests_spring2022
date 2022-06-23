//
// Created by montaha rayyan on 6/22/22.
//


#include "Merchant.h"

void Merchant::applyEncounter(Player &player) const{
    int ignore = 0;
    int addHealthPoints = 1;
    int addForce = 2;
    std::string input;
    bool isDone = false;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins()); // TODO
    while (!isDone){
        std::cin >> input;
        int orderNumber = std::stoi(input);
        //  getline(std::cin, orderNumber);
        if (orderNumber == ignore || orderNumber == addHealthPoints || orderNumber == addForce){
            if (orderNumber == addHealthPoints){
                if (!player.pay(5)){
                    printMerchantInsufficientCoins(std::cout);
                }else{
                    player.heal(1);
                    printMerchantSummary(std::cout, player.getName(), 1, 5);
                }
            }
            if (orderNumber == addForce)
            {
                if (!player.pay(10)){
                    printMerchantInsufficientCoins(std::cout);
                } else{
                    player.buff(1);
                    printMerchantSummary(std::cout, player.getName(), 2, 10);
                }
            }
            if (orderNumber == ignore)
            {
                printMerchantSummary(std::cout, player.getName(), 0, 0);
            }

            isDone = true;
        }else{
            printInvalidInput();
            printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
        }
    }
}

std::string Merchant::getName() const {
    return m_name;
}