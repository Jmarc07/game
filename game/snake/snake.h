#ifndef SNAKE
    #define SNAKE
    #define WIDTH 30
    #define HEIGHT 20
    #define SPEED 200000
    #define START_LENGTH 5

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *body;
    int length;
    char direction;
} Snake;


#endif /* !SNAKE */
