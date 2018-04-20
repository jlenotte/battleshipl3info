// 1 : Message de coup | [ Strike ] | ( on reçoit les coordonnées )
// 8 :         | Fin de partie          | [ char nickname[255]; ] ( Le nickname du vainqueur )
// 7 :         | Bilan tour             | [ SucccessfullStrike strikes[n], Player eliminatedPlayers[n] ] (une liste des tirs réussis + une liste des joueurs éliminés)
// 6 :         | Notification tir       | [ char nickname[255];  ( Le nickname du joueur qui a joué)
// 5 :         | Message échec tir      | [ void ]
// 4 :         | Message succès tir     | [ char nickname[255] ] ( Le nickname du joueur touché )
// 3 :         | Début de tour          | [ void ] ( Notification du début du tour )
// 2 :         | Début de partie        | [ void ] ( Tous les joueurs sont prêts )
// 1 :         | Connection établie     | [ Player player ] ( Confirme la connexion, envoie de la position des bateaux )
typedef struct Boat Boat;
typedef struct Strike Strike;
typedef struct Player Player;
typedef struct SuccessfulStrike SuccessfulStrike;
typedef struct OutgoingMessage OutgoingMessage;
typedef struct IncomingMessage IncomingMessage;

typedef struct Boat {
    int x;
    int y;
    int isAlive;
} s_boat;

struct Player {
    int id;
    char nickname[255];
    Boat boat1;
    Boat boat2;
};

struct Strike {
    int x;
    int y;
    Player fromPlayer;
};

struct SuccessfulStrike {
    char nickPlayerFrom[255];
    char nickPlayerTo[255];
    Boat boat;
};

struct OutgoingMessage {


typedef struct OutgoingMessage {
    int typeMessage;
    char genericMessage[255];
    s_player player;
    char nickname[255];
    SuccessfulStrike strikes[15];
    Player eliminatedPlayers[15];
};

struct IncomingMessage {
    int typeMessage;
    char nickname[255];
    Strike strike;
};
