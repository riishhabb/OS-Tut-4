#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>  
#include "questions.h"



// Global array of questions
question questions[NUM_QUESTIONS];

// Convert string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Initialize the game questions
void initialize_game(void) {
    const char *categories[] = {"programming", "algorithms", "databases"};

    const char *questions_text[] = {
        "What function is used for output in C?",
        "What symbol declares a pointer in C?",
        "Which programming language is mainly used for web development?",
        "Which data structure follows LIFO?",
        "What does Big-O notation describe?",
        "Which algorithm sorts in O(n log n)?",
        "Which algorithm finds the shortest path?",
        "What technique stores subproblem results?",
        "What does SQL stand for?",
        "Which SQL keyword retrieves data?",
        "Which clause filters query results?",
        "What reduces redundancy in databases?"
    };

    const char *answers[] = {
        "printf", "*", "javascript", "stack",
        "time complexity", "merge sort", "dijkstra", "dynamic programming",
        "structured query language", "select", "where", "normalization"
    };

    int index = 0;
    for (int c = 0; c < NUM_CATEGORIES; c++) {
        for (int i = 100; i <= 400; i += 100) {
            strcpy(questions[index].category, categories[c]);
            strcpy(questions[index].question, questions_text[index]);
            strcpy(questions[index].answer, answers[index]);
            questions[index].value = i;
            questions[index].answered = false;
            index++;
        }
    }
}

// Display available categories
void display_categories(void) {
    printf("\nAvailable Categories:\n");
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (!questions[i].answered) {
            printf("- %s for %d points\n", questions[i].category, questions[i].value);
        }
    }
}

// Display a question
void display_question(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value && !questions[i].answered) {
            printf("\nQuestion (%s, %d): %s\n", questions[i].category, value, questions[i].question);
            return;
        }
    }
    printf("Invalid category or question already answered!\n");
}

// Check if all questions are answered
bool all_questions_answered(void) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (!questions[i].answered) {
            return false;
        }
    }
    return true;
}

// Check if a question has already been answered
bool already_answered(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }
    return false;
}

// Validate the player's answer
bool valid_answer(char *category, int value, char *answer) {
    char clean_category[MAX_LEN];
    strncpy(clean_category, category, MAX_LEN);
    to_lowercase(clean_category);

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, clean_category) == 0 && questions[i].value == value) {
            char correct_answer[MAX_LEN];
            strncpy(correct_answer, questions[i].answer, MAX_LEN);
            to_lowercase(correct_answer);

            char user_answer[MAX_LEN];
            strncpy(user_answer, answer, MAX_LEN);
            to_lowercase(user_answer);

            if (strstr(user_answer, correct_answer) != NULL) {
                questions[i].answered = true;  // ✅ Mark question as answered only if correct
                return true;
            }
        }
    }
    return false;
}
