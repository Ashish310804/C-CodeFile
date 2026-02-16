#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define MAX_SNAKE_LENGTH 100

// Snake structure
typedef struct {
    int x, y;
} Point;

// Global variables
Point snake[MAX_SNAKE_LENGTH];
int snake_length;
Point food;
int score;
char direction;
int game_over;

// Function prototypes
void setup();
void draw();
void input();
void logic();
void generate_food();
void gotoxy(int x, int y);
void hide_cursor();

int main() {
    setup();
    hide_cursor();

    while (!game_over) {
        draw();
        input();
        logic();
        Sleep(100); // Delay for game speed
    }

    // Game over screen
    gotoxy(WIDTH/2 - 5, HEIGHT/2);
    printf("GAME OVER!");
    gotoxy(WIDTH/2 - 7, HEIGHT/2 + 1);
    printf("Final Score: %d", score);
    gotoxy(WIDTH/2 - 10, HEIGHT/2 + 2);
    printf("Press any key to exit...");
    getch();

    return 0;
}

void setup() {
    game_over = 0;
    direction = 'd'; // Start moving right
    snake_length = 1;
    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;
    score = 0;

    srand(time(NULL));
    generate_food();
}

void draw() {
    system("cls"); // Clear screen

    // Draw top border
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    // Draw game area
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH + 2; j++) {
            if (j == 0 || j == WIDTH + 1) {
                printf("#"); // Side borders
            } else {
                int is_snake = 0;
                int is_food = 0;

                // Check if current position is snake
                for (int k = 0; k < snake_length; k++) {
                    if (snake[k].x == j - 1 && snake[k].y == i) {
                        if (k == 0) {
                            printf("O"); // Snake head
                        } else {
                            printf("o"); // Snake body
                        }
                        is_snake = 1;
                        break;
                    }
                }

                // Check if current position is food
                if (!is_snake && food.x == j - 1 && food.y == i) {
                    printf("*");
                    is_food = 1;
                }

                // Empty space
                if (!is_snake && !is_food) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    // Draw bottom border
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    // Display score and controls
    printf("Score: %d\n", score);
    printf("Controls: W(up) A(left) S(down) D(right) X(exit)\n");
}

void input() {
    if (_kbhit()) {
        char key = _getch();
        key = tolower(key);

        switch (key) {
            case 'w':
                if (direction != 's') direction = 'w';
                break;
            case 'a':
                if (direction != 'd') direction = 'a';
                break;
            case 's':
                if (direction != 'w') direction = 's';
                break;
            case 'd':
                if (direction != 'a') direction = 'd';
                break;
            case 'x':
                game_over = 1;
                break;
        }
    }
}

void logic() {
    // Move snake body
    for (int i = snake_length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    // Move snake head based on direction
    switch (direction) {
        case 'w':
            snake[0].y--;
            break;
        case 'a':
            snake[0].x--;
            break;
        case 's':
            snake[0].y++;
            break;
        case 'd':
            snake[0].x++;
            break;
    }

    // Check collision with walls
    if (snake[0].x < 0 || snake[0].x >= WIDTH || snake[0].y < 0 || snake[0].y >= HEIGHT) {
        game_over = 1;
    }

    // Check collision with itself
    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            game_over = 1;
        }
    }

    // Check if snake ate food
    if (snake[0].x == food.x && snake[0].y == food.y) {
        score += 10;
        snake_length++;
        generate_food();
    }
}

void generate_food() {
    int valid_position = 0;

    while (!valid_position) {
        food.x = rand() % WIDTH;
        food.y = rand() % HEIGHT;

        valid_position = 1;
        // Make sure food doesn't spawn on snake
        for (int i = 0; i < snake_length; i++) {
            if (snake[i].x == food.x && snake[i].y == food.y) {
                valid_position = 0;
                break;
            }
        }
    }
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hide_cursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
