#ifndef PROTOLIB_H
#define PROTOLIB_H
#include "./type.h"
    int run();
    void menu();
    void displayGameRules();
    Grid createGrid();
    void initGrid(Grid);
    void printGrid(Grid);
    void gotoligcol(int, int);
    Ball * createBall();
    void moveBall(Ball * );
    Blocks * createBlocks(int);
    void initBlocks(Blocks * );
    void distroyBlocks(Blocks * );
    void printBlocks(Blocks * );
    
    Snoopy * createSnoopy();
    void initSnoopy(Snoopy * );

    Birds * CreateBirds();
    void printBirds(Birds * );
    
    void btnDetection(Grid);
    void positionSnoopy();
    void startNewGame();    
#endif
