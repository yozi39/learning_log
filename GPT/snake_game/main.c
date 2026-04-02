#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define BOARD_WIDTH 30
#define BOARD_HEIGHT 20
#define MAX_SNAKE_LENGTH (BOARD_WIDTH * BOARD_HEIGHT)
#define INITIAL_SPEED_MS 120
#define MIN_SPEED_MS 60

typedef struct {
    int x;
    int y;
} Point;

typedef enum {
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} Direction;

static Point snake[MAX_SNAKE_LENGTH];
static int snake_length;
static Point food;
static Direction direction;
static bool is_game_over;
static int score;
static int speed_ms;

static void move_cursor_to_top(void) {
    COORD coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

static void hide_cursor(void) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info;

    GetConsoleCursorInfo(console, &cursor_info);
    cursor_info.bVisible = FALSE;
    SetConsoleCursorInfo(console, &cursor_info);
}

static void setup_console(void) {
    system("cls");
    system("title Snake Game");
    hide_cursor();
}

static bool is_on_snake(int x, int y) {
    for (int i = 0; i < snake_length; i++) {
        if (snake[i].x == x && snake[i].y == y) {
            return true;
        }
    }
    return false;
}

static void spawn_food(void) {
    do {
        food.x = rand() % BOARD_WIDTH;
        food.y = rand() % BOARD_HEIGHT;
    } while (is_on_snake(food.x, food.y));
}

static void init_game(void) {
    snake_length = 3;
    snake[0].x = BOARD_WIDTH / 2;
    snake[0].y = BOARD_HEIGHT / 2;
    snake[1].x = snake[0].x - 1;
    snake[1].y = snake[0].y;
    snake[2].x = snake[1].x - 1;
    snake[2].y = snake[1].y;

    direction = DIR_RIGHT;
    is_game_over = false;
    score = 0;
    speed_ms = INITIAL_SPEED_MS;
    spawn_food();
}

static void draw_border(void) {
    for (int x = 0; x < BOARD_WIDTH + 2; x++) {
        putchar('#');
    }
    putchar('\n');
}

static void draw_game(void) {
    move_cursor_to_top();
    printf("Snake Game  Score: %d  Speed: %dms\n", score, speed_ms);
    printf("Controls: W A S D to move, Q to quit\n");

    draw_border();

    for (int y = 0; y < BOARD_HEIGHT; y++) {
        putchar('#');
        for (int x = 0; x < BOARD_WIDTH; x++) {
            if (snake[0].x == x && snake[0].y == y) {
                putchar('@');
            } else if (food.x == x && food.y == y) {
                putchar('*');
            } else if (is_on_snake(x, y)) {
                putchar('O');
            } else {
                putchar(' ');
            }
        }
        putchar('#');
        putchar('\n');
    }

    draw_border();
}

static void update_direction(void) {
    if (!_kbhit()) {
        return;
    }

    char input = (char)_getch();

    if (input >= 'A' && input <= 'Z') {
        input = (char)(input - 'A' + 'a');
    }

    if (input == 'w' && direction != DIR_DOWN) {
        direction = DIR_UP;
    } else if (input == 's' && direction != DIR_UP) {
        direction = DIR_DOWN;
    } else if (input == 'a' && direction != DIR_RIGHT) {
        direction = DIR_LEFT;
    } else if (input == 'd' && direction != DIR_LEFT) {
        direction = DIR_RIGHT;
    } else if (input == 'q') {
        is_game_over = true;
    }
}

static Point next_head_position(void) {
    Point head = snake[0];

    if (direction == DIR_UP) {
        head.y--;
    } else if (direction == DIR_DOWN) {
        head.y++;
    } else if (direction == DIR_LEFT) {
        head.x--;
    } else if (direction == DIR_RIGHT) {
        head.x++;
    }

    return head;
}

static bool hits_wall(Point next_head) {
    return next_head.x < 0 || next_head.x >= BOARD_WIDTH ||
           next_head.y < 0 || next_head.y >= BOARD_HEIGHT;
}

static bool hits_self(Point next_head, bool grow) {
    int limit = grow ? snake_length : snake_length - 1;

    for (int i = 0; i < limit; i++) {
        if (snake[i].x == next_head.x && snake[i].y == next_head.y) {
            return true;
        }
    }
    return false;
}

static void move_snake(Point next_head, bool grow) {
    if (grow) {
        for (int i = snake_length; i > 0; i--) {
            snake[i] = snake[i - 1];
        }
        snake[0] = next_head;
        snake_length++;
        return;
    }

    for (int i = snake_length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    snake[0] = next_head;
}

static void update_game(void) {
    Point next_head = next_head_position();
    bool grow = next_head.x == food.x && next_head.y == food.y;

    if (hits_wall(next_head) || hits_self(next_head, grow)) {
        is_game_over = true;
        return;
    }

    if (grow) {
        move_snake(next_head, true);
        score += 10;
        if (speed_ms > MIN_SPEED_MS) {
            speed_ms -= 5;
        }

        if (snake_length >= MAX_SNAKE_LENGTH) {
            is_game_over = true;
            return;
        }

        spawn_food();
    } else {
        move_snake(next_head, false);
    }
}

static void game_over_screen(void) {
    printf("\nGame over. Final score: %d\n", score);
    printf("Press any key to exit...\n");
    _getch();
}

int main(void) {
    srand((unsigned int)time(NULL));
    setup_console();
    init_game();

    while (!is_game_over) {
        draw_game();
        update_direction();
        update_game();
        Sleep(speed_ms);
    }

    draw_game();
    game_over_screen();
    return 0;
}
