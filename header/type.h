#ifndef TYPE_H
#define TYPE_H

#define ROW 10
#define COL 20 

typedef struct {
    int x;
    int y;
}Position;


typedef struct {
    char* ship;
    Position Position;
}Object;

typedef struct {
    
}Player;

typedef struct {
    Object Object;
}Snoopy;


typedef struct {
    Object** Array;
    int nbrBlock;
}Blocks;

typedef struct {
    Object Object;
    int direction;
}Ball;

typedef struct {
    Object Bird_1;
    Object Bird_2;
    Object Bird_3;
    Object Bird_4;
}Birds;

typedef struct {
    int level;
    int time;
    int life;
}Param;

typedef struct {
    Snoopy Snoopy;
    Ball Ball;
    Blocks Blocks;
}Items;

typedef struct {
    char** Array;
    int row;
    int col;
    Param Param;
    Items Items;
}Grid;

typedef struct {
    
}Game;


#endif