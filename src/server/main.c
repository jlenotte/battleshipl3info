#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "../shared/message.h"
#include "../shared/constants.h"

Player playerSlots[15];

int areBoatCoordinatesTheSame(Boat boat, int x, int y);
void createPlayer(int socketId, char *nickName);
int checkIfBoatSlotAlreadyOccupied(int x, int y);
Boat createBoat();

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

int main()
{
    srand(time(NULL));

    createPlayer(0, "Daniel");
    printf("\n%s", playerSlots[0].nickname);
    printf("%d", playerSlots[0].boat2.x);

    createPlayer(1, "Daniel");
    printf("%s", playerSlots[1].nickname);
    printf("%d", playerSlots[1].boat2.x);

    createPlayer(2, "Daniel");
    printf("%s", playerSlots[2].nickname);
    printf("%d", playerSlots[2].boat2.x);

    createPlayer(3, "Daniel");
    printf("%s", playerSlots[3].nickname);
    printf("%d", playerSlots[3].boat2.x);

    createPlayer(4, "Daniel");
    printf("%s", playerSlots[4].nickname);
    printf("%d", playerSlots[4].boat2.x);

    return 0;
}