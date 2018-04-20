//
// Created by okno on 4/20/18.
//
struct Player {
    int id;
    char nickname[255];
    Boat boat1;
    Boat boat2;
};

struct Boat {
    int x;
    int y;
    int isAlive;
};

struct Strike {
    int x;
    int y;
    Player from;
};

struct SuccessfullStrike {
    char nickPlayerFrom[255];
    char n
    ickPlayerTo[255];
    Boat boat;
};

A// le type message définit ce qu'il faut lire dans la struct envoyé

// typeMessage | description            | [ type ] |

// 4 :         | Message succès tir     | [ char nickname[255] ] ( nom du joueur toucher )
// 5 :         | Message échec tir      | [ void ]
// 6 :         | Notification tir       | [ char genericMessage[255]; ] ( "le joueur n a joué")
// 7 :         | Bilan tour             | [ SucccessfullStrike strikes[n], Player eliminatedPlayers[n] ]
// 8 :         | Fin de partie          | [ char genericMessage[255]; ] ( "La partie est terminée, bravo Daniel" )

struct OutgoingMessage {
    int typeMessage;
    char genericMessage[255];
    Player player;
};

// 0 : Message nickname | [ char nickname[255] ] | ( le pseudo du joueur )
// 0 : Message de coup | [ Strike ] | ( on reçoit les coordonnées )
struct IncomingMessage {
    int typeMessage;
    char nickname[255];
    Strike strike;
};
