PART 1 (Improved Existing C Game)
(Assignment 2 – Part 1)
1. Introduction

This assignment was about understanding an existing C game and then improving it.
The original game was a very simple console game where the player moves up and down to avoid an obstacle.

After studying the code, I added new features and also fixed the logic so the game works smoothly.

2. Original Game Summary

The original game:

Had only one obstacle

Did not have a score system

Ended immediately when the player got hit

Had no menu or instructions

Had some bugs and didn’t restart properly

It was based on a simple loop, keyboard input, and collision checking.

3. Improvements I Added

I added three main improvements:

✔ 1. Score System

Every time the obstacle completes a full pass, the score increases.

✔ 2. Lives System (3 Lives)

Instead of instant Game Over, the player now has 3 lives.
When the player touches the obstacle, 1 life is lost.

✔ 3. Working Menu + Restart Option

I added:

1. Start Game
2. Instructions
3. Exit


After Game Over, the player can press Y to restart the game without closing the program.

4. How the Game Works Now

The player is represented by P

The obstacle is O

Player uses W and S to move

Obstacle moves from right to left

Score increases every time the obstacle resets

If the obstacle hits the player → lives decrease

When lives reach 0 → Game Over screen is shown

Player can restart the game immediately

Game speed increases slowly to make it more challenging

5. Controls
W → Move Up  
S → Move Down  
Q → Quit Game

6. Sample Output (ASCII Screenshot)
##########################################
# P                                      #
#                                        #
#                                        #
#                             O          #
##########################################
Score: 4    Lives: 2
Controls → W = Up | S = Down | Q = Quit

7. Files Included
part1_game_fixed.c    → The improved and fixed game code
README.md             → Documentation (this file)

8. What I Learned

How to understand and analyze someone else’s code

How a game loop works in C

How to move characters on screen using console refresh

How to handle non-blocking keyboard input (kbhit() + getch())

How to improve a program using functions

How to implement score, lives, and a menu system

How to debug and fix runtime errors

9. Conclusion

This assignment helped me understand practical C programming much better.
By improving the game, I learned how to structure code, fix bugs, and add new features.
The improved version is more user-friendly and enjoyable to play.
