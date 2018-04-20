# battleshipl3info
Battleship project for the Linux/Machine architecture class (L3 Info CNAM Lille)

## Procedure

- Connection to server
- Message from server to client to confirm connection
- Message from server to all clients to display awaiting players to connect
- Once all clients are connected, server sends a notification of the game start
- Message from server to all clients to notify the start of a turn, the players then have to play
- Message from clients to server with the strike information
- Message from server to client to notify if strike as successful or not, if successful, information about which player was hit, the boat coordinates, etc. 
- Battle report sent from server to all clients, including a table with all successful and missed strikes
