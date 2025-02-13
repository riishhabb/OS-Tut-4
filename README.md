# OS-Tut-
# Jeopardy Game - C Implementation

## Description
This is a command-line-based **Jeopardy game** written in C. The game allows four players to take turns selecting categories and answering trivia questions. The player with the highest earnings at the end wins the game.

---

## 🛠 Features
- Supports **4 players**.
- Players take turns selecting questions.
- Questions are categorized into **Programming, Algorithms, and Databases**.
- Players must answer questions in **"What is"** or **"Who is"** format.
- The game keeps track of **scores** and **displays a leaderboard** at the end.

---

## 🚀 Installation & Compilation
### **1. Compile the Program**
Use GCC to compile the source files:
```sh
gcc -o jeopardy jeopardy.c players.c questions.c -Wall
