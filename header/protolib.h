#ifndef PROTOLIB_H
#define PROTOLIB_H
#include "./type.h"
    int run();
    void menu();
    void displayGameRules();
    Grid createGrid();
    void initGrid(Grid);
    void printGrid(Grid);
    void btnDetection(Grid);
    Blocks * createBlocks(int nbrBlock);
    void initBlocks(Blocks * blocks);
    void distroyBlocks(Blocks * blocks);
    void printBlocks(Blocks * blocks);
    
    void positionSnoopy();
    void startNewGame();
#endif
