// Rock-Paper-Scissors-Spock-Lizard
// A program that lets you play RPSSL against
// The computer by randomly generating computer moves

// Necessary library functions.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining messages:
const char welcomeMessage[] = "Welcome to RPSSL ✊ 📜 ✂️ 🖖 🦎\n";
const char gameModeQuestion[] = "(s) Single player\n(e) Exit\n";
const char pointsQuestion[] = "How many points to win?\n";
const char userPrompt[] = "Select an option: ";
const char gameStart[] = "Starting game 🎉\n\n";
const char goodbyeMessage[] = "Goodbye 👋";
const char movePrompt[] = "Please select a Move: \n"
                          "0 ✊ || 1 🦎 || 2 🖖 || 3 ✂️ || 4 📜     : ";
const char errorMessage[] = "ERROR: Invalid input.\n";
const char moveErrorMessage[] =
    "Move key %d does not exist. Please try again.\n";

// Variables necessary for game logic.
char gameMode = 0;
int maxPoints = 5;
int p1Move = 0;
int p2Move = 0;
int p1Score = 0;
int p2Score = 0;

// Main function
int main() {
  // Seeding rand() with the current time.
  srand(time(NULL));

  printf(welcomeMessage);

  // Main loop.
  while (1) {
    printf("%s", gameModeQuestion);
    printf("%s", userPrompt);

    // Prompts the player to enter a character for the gamemode.
    gameMode = getchar();
    // Clearing the input buffer after reading gamemode.
    int ch;
    // Clear input buffer up to and including newline.
    while ((ch = getchar()) != '\n' && ch != EOF)
      ;

    // If the entered gamemode is Singleplayer, the following loop starts.
    while (gameMode == 's') {
      printf("%s", pointsQuestion);
      printf("%s", userPrompt);

      // Ask player for points to win.
      // If scanf can't parse an int (returns 0), show error.
      int validMaxPoints = scanf("%d", &maxPoints);
      // Clearing the input buffer after reading point maximum.
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF)
        ;

      // If the max point input was valid, starts the loop for game logic.
      if (validMaxPoints) {
        printf("%s", gameStart);

        // Game logic loop
        while (p1Score < maxPoints && p2Score < maxPoints) {
          printf(movePrompt);

          // Prompts the player to enter a move. Shows an error if not an int.
          int validMove = scanf("%d", &p1Move);
          // Clearing the input buffer after reading player move.
          int ch;
          while ((ch = getchar()) != '\n' && ch != EOF)
            ;

          // Checks if the move key was valid and within the required range.
          if (validMove) {
            if (p1Move >= 0 && p1Move <= 4) {
              // Generates a random move key from 0-4 for the computer move.
              p2Move = rand() % 5;
              printf("Computer: %d\n", p2Move);

              // Calculates the difference between the player move and
              // computer move and finds the winner based on game logic chart.
              switch (p1Move - p2Move) {
              case -4:
                p2Score++;
                printf("👫:🤖   %d:%d\n", p1Score, p2Score);
                break;
              case -3:
                p1Score++;
                printf("👫:🤖   %d:%d\n", p1Score, p2Score);
                break;
              case -2:
                p2Score++;
                printf("👫:🤖   %d:%d\n", p1Score, p2Score);
                break;
              case -1:
                p1Score++;
                printf("👫:🤖   %d:%d\n", p1Score, p2Score);
                break;
              case 0:
                printf("It was a tie!\n");
                printf("👫:🤖   %d:%d\n", p1Score, p2Score);
                break;
              case 1:
                p2Score++;
                printf("👫:🤖   %d:%d\n", p1Score, p2Score);
                break;
              case 2:
                p1Score++;
                printf("👫:🤖   %d:%d\n", p1Score, p2Score);
                break;
              case 3:
                p2Score++;
                printf("👫:🤖   %d:%d\n", p1Score, p2Score);
                break;
              case 4:
                p1Score++;
                printf("👫:🤖   %d:%d\n", p1Score, p2Score);
                break;
              }
              // If the player enters a move key outside the required range,
              // prints the move key and says that it's invalid.
            } else {
              printf(moveErrorMessage, p1Move);
            }
            // If the move was of an invalid data-type, shows an error.
          } else {
            printf("%s", errorMessage);
          }
        }
        // Shows the winner based on who has the higher score on game end.
        if (p1Score > p2Score) {
          printf("Player 👫 wins!\n");
        } else if (p1Score < p2Score) {
          printf("Computer 🤖 wins!\n");
        }
        // Sets the gamemode to 'e', exiting the program.
        gameMode = 'e';
        // If the max point input was of an invalid data-type, shows an error.
      } else {
        printf("%s", errorMessage);
      }
      // Breaks the main loop as soon as the gamemode is 'e'
    }
    if (gameMode == 'e') {
      break;
    }

    // Shows an error if the gamemode input isn't any specified option.
    printf("%s", errorMessage);
  }
  // Says goodbye after the main loop is done.
  printf("%s", goodbyeMessage);
}