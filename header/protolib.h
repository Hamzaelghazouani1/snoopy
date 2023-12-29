#ifndef PROTOLIB_H
#define PROTOLIB_H
#include <stdio.h>
#include <stdlib.h>
#include "./type.h"

    int run(void);
    void menu(void);

    void displayGameRules(void);
    
    void saveGame(Grid*);
    void resumeGame(void);
    void loadGame(Grid*);
    void startNewGame(void);
    
    void printWin(Grid*);
    void printGameOver(Grid*);
    void printSettings(Grid*);
    void printGrid(Grid*);
    void printBlocks(Blocks*);
    void printBirds(Birds*);

    void downLife(Grid* grid);
    void moveSnoopy(Grid*,int);
    void playGame(Grid *);
    void removeBird(Grid*);

    Grid* createGrid(void);
    void initGrid(Grid*);
    void gotoligcol(int, int);

    Ball* createBall(void);
    void moveBall(Ball*);

    Blocks* createBlocks(int);
    void initBlocks(Blocks*);
    void distroyBlocks(Blocks*);

    Snoopy* createSnoopy(void);
    void initSnoopy(Snoopy* );

    Birds* createBirds(void);
#endif
