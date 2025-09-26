#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

char gameMode;
int maxPoints = 5;
int p1Move;
int p2Move;
int p1Score = 0;
int p2Score = 0;

int main() {
  srand(time(NULL));

  printf(welcomeMessage);

  while (1) {
    printf("%s", gameModeQuestion);
    printf("%s", userPrompt);

    gameMode = getchar();
    // Clearing the input buffer after reading gamemode.
    int ch;
    // Every time getchar() is called it advances the buffer by 1
    // The while loop keeps ckecking the condition and doing nothing
    // in its body, clearing everything in the buffer until it reaches
    // a newline or EOF (already having cleare \n), clearing the buffer.
    while ((ch = getchar()) != '\n' && ch != EOF)
      ;

    while (gameMode == 's') {
      printf("%s", pointsQuestion);
      printf("%s", userPrompt);

      int validMaxPoints = scanf("%d", &maxPoints);
      // Clearing the input buffer after reading point maximum.
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF)
        ;

      if (validMaxPoints) {
        printf("%s", gameStart);

        while (p1Score < maxPoints && p2Score < maxPoints) {
          printf(movePrompt);

          int validMove = scanf("%d", &p1Move);
          // Clearing the input buffer after reading player move.
          int ch;
          while ((ch = getchar()) != '\n' && ch != EOF)
            ;

          if (validMove) {
            if (p1Move >= 0 && p1Move <= 4) {
              p2Move = rand() % 5;
              printf("Computer: %d\n", p2Move);

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
            } else {
              printf(moveErrorMessage, p1Move);
            }
          } else {
            printf("%s", errorMessage);
          }
        }
        if (p1Score > p2Score) {
          printf("Player 👫 wins!\n");
        } else if (p1Score < p2Score) {
          printf("Computer 🤖 wins!\n");
        }
        gameMode = 'e';
      } else {
        printf("%s", errorMessage);
      }
    }
    if (gameMode == 'e') {
      break;
    }

    printf("%s", errorMessage);
  }
  printf("%s", goodbyeMessage);
}