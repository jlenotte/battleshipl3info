typedef struct Player;

struct Player {
    int id;
    char nickname[255];
    Boat boat1;
    Boat boat2;
};

typedef struct Boat;

struct Boat {
    int x;
    int y;
    int isAlive;
};

typedef struct Strike;

struct Strike {
    int x;
    int y;
    Player from;
};

typedef struct SuccessfullStrike;

struct SuccessfullStrike {
    char nickPlayerFrom[255];
    char nickPlayerTo[255];
    Boat boat;
};


// le type message définit ce qu'il faut lire dans la struct envoyé

// typeMessage | description            | [ type ] |
// 0 :         | En attente connection   | [ char genericMessage[255]; ] ( "En attente de connection n joueurs" )
// 1 :         | Connection établie     | [ Player player ] ( Confirme la connexion, envoie de la position des bateaux )
// 2 :         | Début de partie        | [ void ] ( Tous les joueurs sont prêts )
// 3 :         | Début de tour          | [ void ] ( Notification du début du tour )
// 4 :         | Message succès tir     | [ char nickname[255] ] ( Le nickname du joueur touché )
// 5 :         | Message échec tir      | [ void ]
// 6 :         | Notification tir       | [ char nickname[255];  ( Le nickname du joueur qui a joué)
// 7 :         | Bilan tour             | [ SucccessfullStrike strikes[n], Player eliminatedPlayers[n] ] (une liste des tirs réussis + une liste des joueurs éliminés)
// 8 :         | Fin de partie          | [ char nickname[255]; ] ( Le nickname du vainqueur )

typedef struct OutgoingMessage;

struct OutgoingMessage {
    int typeMessage;
    char genericMessage[255];
    Player player;
    char nickname[255];
    SuccessfullStrike strikes[15];
    Player eliminatedPlayers[15];
};

// 0 : Message nickname | [ char nickname[255] ] | ( le pseudo du joueur )
// 1 : Message de coup | [ Strike ] | ( on reçoit les coordonnées )

typedef struct IncomingMessage;

struct IncomingMessage {
    int typeMessage;
    char nickname[255];
    Strike strike;
};