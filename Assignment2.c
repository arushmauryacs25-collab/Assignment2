#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 15

int playerY;
int obstacleX, obstacleY;
int score;
int lives;
int speed;

// Draw border
void drawBorder(void) {
    for (int i = 0; i < WIDTH + 2; i++) putchar('#');
    putchar('\n');
}

// Draw the game screen
void drawScreen(void) {
    system("cls");

    drawBorder();

    for (int y = 0; y < HEIGHT; y++) {
        putchar('#');
        for (int x = 0; x < WIDTH; x++) {
            if (y == playerY && x == 2)
                putchar('P');          // player
            else if (y == obstacleY && x == obstacleX)
                putchar('O');          // obstacle
            else
                putchar(' ');
        }
        putchar('#');
        putchar('\n');
    }

    drawBorder();
    printf("Score: %d    Lives: %d\n", score, lives);
    printf("Controls ? W = Up | S = Down | Q = Quit\n");
}

// Reset obstacle position
void resetObstacle(void) {
    obstacleX = WIDTH - 2;
    obstacleY = rand() % HEIGHT;
    // Increase score when obstacle fully passed
    score++;
    if (speed > 40) speed -= 2;
}

// Check collision (player is at x==2)
int checkCollision(void) {
    return (playerY == obstacleY && obstacleX == 2);
}

// Game loop (non-recursive)
void startGame(void) {
    int playing = 1;

    // initialize for each play
    playerY = HEIGHT / 2;
    score = 0;
    lives = 3;
    speed = 120;
    obstacleX = WIDTH - 2;
    obstacleY = rand() % HEIGHT;

    while (playing) {
        drawScreen();

        // handle input (non-blocking)
        if (kbhit()) {
            char ch = getch();
            if (ch == 'w' || ch == 'W') {
                if (playerY > 0) playerY--;
            } else if (ch == 's' || ch == 'S') {
                if (playerY < HEIGHT - 1) playerY++;
            } else if (ch == 'q' || ch == 'Q') {
                // quit current game to menu
                return;
            }
        }

        // move obstacle
        obstacleX--;

        if (obstacleX <= 0) {
            resetObstacle();
        }

        // collision check
        if (checkCollision()) {
            lives--;
            // simple hit feedback beep
            Beep(400, 120);

            if (lives <= 0) {
                // Game Over screen
                system("cls");
                printf("\n\n===== GAME OVER =====\n");
                printf("Final Score: %d\n", score);
                printf("Play Again? (Y/N): ");

                // wait for valid response
                while (1) {
                    if (kbhit()) {
                        char c = getch();
                        if (c == 'y' || c == 'Y') {
                            // restart: re-init and continue outer while loop
                            playerY = HEIGHT / 2;
                            score = 0;
                            lives = 3;
                            speed = 120;
                            obstacleX = WIDTH - 2;
                            obstacleY = rand() % HEIGHT;
                            break;
                        } else if (c == 'n' || c == 'N') {
                            // exit to menu
                            return;
                        }
                    }
                    Sleep(50);
                }
            } else {
                // reset obstacle after a hit so player has a moment
                obstacleX = WIDTH - 2;
                obstacleY = rand() % HEIGHT;
            }
        }

        Sleep(speed);
    }
}

// Flush stdin after numeric scanf
void flush_stdin(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

// Main menu
void menu(void) {
    int choice = 0;

    while (1) {
        system("cls");
        printf("===============================\n");
        printf("        SIMPLE C GAME\n");
        printf("===============================\n");
        printf("1. Start Game\n");
        printf("2. Instructions\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            // invalid input, clear and continue
            flush_stdin();
            continue;
        }
        flush_stdin(); // remove leftover newline

        if (choice == 1) {
            startGame();
        } else if (choice == 2) {
            system("cls");
            printf("======= GAME INSTRUCTIONS =======\n");
            printf("? Avoid the obstacle (O)\n");
            printf("? Move using 'W' (up) and 'S' (down)\n");
            printf("? You get 3 lives\n");
            printf("? Score increases every time obstacle resets\n");
            printf("\nPress any key to go back...");
            getch();
        } else if (choice == 3) {
            system("cls");
            printf("Exiting... Goodbye!\n");
            Sleep(800);
            break;
        } else {
            // loop again for invalid menu
            continue;
        }
    }
}

int main(void) {
    srand((unsigned)time(NULL));
    menu();
    return 0;
}
