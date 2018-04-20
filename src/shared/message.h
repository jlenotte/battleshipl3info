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

typedef struct OutgoingMessage {
    int typeMessage;
    char genericMessage[255];
    s_player player;
    char nickname[255];
    SuccessfulStrike strikes[15];
    Player eliminatedPlayers[15];
};

// 0 : Message nickname | [ char nickname[255] ] | ( le pseudo du joueur )

struct IncomingMessage {
    int typeMessage;
    char nickname[255];
    Strike strike;
};

// 0 :         | En attente connection   | [ char genericMessage[255]; ] ( "En attente de connection n joueurs" )
