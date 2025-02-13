#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <stdbool.h> 

#define MAX_NAME_LEN 50

// Player structure
typedef struct {
    char name[MAX_NAME_LEN];
    int score;
} player;

// Function prototypes
void initialize_players(player players[], int num_players);
bool player_exists(player players[], int num_players, char *name);
void update_score(player players[], int num_players, char *name, int score);
void show_results(player players[], int num_players);

#endif /* PLAYERS_H_ */
