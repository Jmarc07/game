//currently working on it it's with ncurses

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "snake.h"


void initializeSnake(Snake *snake)
{
    snake->length = START_LENGTH;
    snake->body = malloc(snake->length * sizeof(Point));
    for (int i = 0; i < snake->length; i++) {
        snake->body[i] = (Point){WIDTH / 2, HEIGHT / 2};
    }
    snake->direction = 'R';
}

void moveSnake(Snake *snake)
{
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }
    switch (snake->direction) {
        case 'U': snake->body[0].y--; break;
        case 'D': snake->body[0].y++; break;
        case 'L': snake->body[0].x--; break;
        case 'R': snake->body[0].x++; break;
    }
}

void displaySnake(Snake *snake)
{
    for (int i = 0; i < snake->length; i++) {
        mvprintw(snake->body[i].y, snake->body[i].x, "P");
    }
}

void freeSnake(Snake *snake)
{
    free(snake->body);
}

int main(void)
{
    srand(time(NULL));
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    Snake snake;
    initializeSnake(&snake);
    int foodX, foodY;
    int score = 0;

    while (1) {
        clear();
        if (score == 0) {
            foodX = rand() % WIDTH;
            foodY = rand() % HEIGHT;
        }
        mvprintw(foodY, foodX, "O");
        moveSnake(&snake);
        if (snake.body[0].x == foodX && snake.body[0].y == foodY) {
            score++;
            snake.length++;
            snake.body = realloc(snake.body, snake.length * sizeof(Point));
            snake.body[snake.length - 1] = snake.body[snake.length - 2];
        }
        for (int i = 1; i < snake.length; i++) {
            if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
                endwin();
                printf("Game Over! Your score: %d\n", score);
                freeSnake(&snake);
                return 0;
            }
        }
        if (snake.body[0].x < 0 || snake.body[0].x >= WIDTH || snake.body[0].y < 0 || snake.body[0].y >= HEIGHT) {
            endwin();
            printf("Game Over! Your score: %d\n", score);
            freeSnake(&snake);
            return 0;
        }
        displaySnake(&snake);
        mvprintw(0, 0, "Score: %d", score);
        refresh();
        usleep(SPEED);
    }
    endwin();
    return 0;
}
