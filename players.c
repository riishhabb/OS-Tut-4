#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "players.h"

// Initialize players
void initialize_players(player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d name: ", i + 1);
        fgets(players[i].name, MAX_NAME_LEN, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = '\0'; // Remove newline
        players[i].score = 0;
    }
}

// Check if a player exists
bool player_exists(player players[], int num_players, char *name) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

// Update player scores
void update_score(player players[], int num_players, char *name, int score) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].score += score;
            return;
        }
    }
}

// Display final scores in descending order
void show_results(player players[], int num_players) {
    printf("\nFinal Scores:\n");

    // Sort players based on score (descending order)
    for (int i = 0; i < num_players - 1; i++) {
        for (int j = 0; j < num_players - i - 1; j++) {
            if (players[j].score < players[j + 1].score) {
                player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    // Print rankings
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d points\n", players[i].name, players[i].score);
    }
}
