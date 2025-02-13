#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jeopardy.h"

int main() {
    player players[NUM_PLAYERS];
    char buffer[BUFFER_LEN];

    printf("Welcome to Jeopardy!\n");

    // Initialize players
    initialize_players(players, NUM_PLAYERS);

    // Initialize questions
    initialize_game();

    // Start game loop
    while (!all_questions_answered()) {
        display_categories();

        // Select a player to choose the question
        char player_name[MAX_NAME_LEN];
        printf("\nEnter player name to choose a question: ");
        fgets(player_name, MAX_NAME_LEN, stdin);
        player_name[strcspn(player_name, "\n")] = 0; // Remove newline

        // Validate player exists
        if (!player_exists(players, NUM_PLAYERS, player_name)) {
            printf("Invalid player name. Try again.\n");
            continue;
        }

        // Get category and value
        printf("\nEnter a category and value (e.g., 'programming 200'): ");
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        char category[BUFFER_LEN];
        int value;
        if (sscanf(buffer, "%255s %d", category, &value) != 2) {
            printf("Invalid input format. Try again.\n");
            continue;
        }

        // Check if the question is already answered
        if (already_answered(category, value)) {
            printf("That question has already been answered! Pick another.\n");
            continue;
        }

        // Display the question
        display_question(category, value);

        // Prompt for answer
        printf("\nEnter your answer: ");
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        // Check if the answer is correct
        if (valid_answer(category, value, buffer)) {
            printf("Correct!\n");
            update_score(players, NUM_PLAYERS, player_name, value); // ✅ Update player score
        } else {
            printf("Incorrect! The correct answer was: %s\n", questions[value / 100 - 1].answer);
        }

        // Mark the question as answered
        for (int i = 0; i < NUM_QUESTIONS; i++) {
            if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
                questions[i].answered = true;
                break;
            }
        }
    }

    printf("\nGame Over!\n");
    show_results(players, NUM_PLAYERS);

    return 0;
}
