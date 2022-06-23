#include "../Mtmchkin.h"
int main(){
    const int MAX_NUMBER_OF_ROUNDS = 100;
    printStartGameMessage();
    Mtmchkin game("deck.txt");
    while (!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS){
        game.playRound();
    }
    game.printLeaderBoard();

    return 0;
}