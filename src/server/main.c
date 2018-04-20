#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <gmpxx.h>

#include "../shared/message.h"
#include "../shared/constants.h"

Player playerSlots[15];
SuccessfulStrike successfulStrikes[15];

int areBoatCoordinatesTheSame(Boat boat, int x, int y);
void createPlayer(int socketId, char *nickName);
int checkIfBoatSlotAlreadyOccupied(int x, int y);
Boat createBoat();

void updateSuccessfulStrike(Strike *strike, Player *player);

int checkIfBoatSlotAlreadyOccupied(int x, int y) {
    for (int i = 0; i < 15; i++) {
        if (areBoatCoordinatesTheSame(playerSlots[i].boat1, x, y)
            && areBoatCoordinatesTheSame(playerSlots[i].boat2, x, y)) {
            return 0;
        }
    }
}

Boat createBoat() {
    int x;
    int y;
    Boat boat;

    do {
        x = rand() % 17;
        y = rand() % 17;
    } while (checkIfBoatSlotAlreadyOccupied(x, y));

    boat.x = x;
    boat.y = y;
    boat.isAlive = 1;

    return boat;
}

void createPlayer(int socketId, char *nickName) {
    playerSlots[socketId].id = socketId;
    strcpy(playerSlots[socketId].nickname, nickName);

    playerSlots[socketId].boat1 = createBoat();
    playerSlots[socketId].boat2 = createBoat();
}

int areBoatCoordinatesTheSame(Boat boat, int x, int y) {
    if (boat.x == x && boat.y == y) {
        return 1;
    }

    return 0;
}

int checkIfCoordinatesAreValid(int x, int y) {
    if (x < 17 && y < 17 && x >=0 && y >= 0){
        return 1;
    }
    return 0;
}

int checkIfStrikeSuccessful(Strike strike, Player player)
{
    if(areBoatCoordinatesTheSame(player.boat1, strike.x, strike.y)){
        updateSuccessfulStrike(&strike, &player);
        return 1;
    }

    if(areBoatCoordinatesTheSame(player.boat2, strike.x, strike.y)){
        updateSuccessfulStrike(&strike, &player);
        return 1;
    }

    return 0;

}

void updateSuccessfulStrike(Strike *strike, Player *player) {
    (*player).boat1.isAlive = 0;
    SuccessfulStrike success;
    strcpy(success.nickPlayerFrom, (*strike).fromPlayer.nickname);
    strcpy(success.nickPlayerTo, (*player).nickname);
    success.boat = (*player).boat1;

    for(int i = 0; i < NB_PLAYER_MAX; i++)
    {
        if (!strcmp(successfulStrikes[i].nickPlayerTo, "UNDEFINED" )) {
            successfulStrikes[i] = success;
            break;
        }
    }
}

void computeStrike(Strike strike) {

    if(checkIfCoordinatesAreValid(strike.x, strike.y)) {
        for( int i = 0; i < NB_PLAYER_MAX; i++ ) {
            if (checkIfPlayerIsDead(playerSlots[i]) || !checkIfStrikeSuccessful(strike, playerSlots[i])) {
                printf("Echec du tir");
            } else {
                printf("Tir réussi !");
            }
        }
    } else {
        printf("le coup est hors du plateau");
    }
}

void initializeSuccessfulStrikes() {
    for(int i = 0; i < NB_PLAYER_MAX; i++){
        strcpy(successfulStrikes[i].nickPlayerTo, "UNDEFINED");
    }
}

int checkIfPlayerIsDead(Player player) {
    if(!player.boat1.isAlive && !player.boat2.isAlive) {
        return 1;
    }

    return 0;
}

int main()
{
    srand(time(NULL));

    return 0;
}