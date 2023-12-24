#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../header/type.h"
#include "../header/protolib.h"

Blocks* createBlocks(int nbrBlock) {
    Blocks* blocks = (Blocks*)malloc(sizeof(Blocks));
    blocks->nbrBlock = nbrBlock;
    blocks->Array = (Object**)malloc(nbrBlock * sizeof(Object*));
    for (int i = 0; i < nbrBlock; i++) {
        blocks->Array[i] = (Object*)malloc(sizeof(Object));
    }
    return blocks;
}


void initBlocks(Blocks* blocks) {
    for (int i = 0; i < blocks->nbrBlock; i++) {
        do {
            blocks->Array[i]->Position.x = rand() % 20;
        } while (blocks->Array[i]->Position.x <= 2 || blocks->Array[i]->Position.x % 2 != 0);

        do {
            blocks->Array[i]->Position.y = rand() % 80;
        } while (blocks->Array[i]->Position.y <= 2 || blocks->Array[i]->Position.y % 4 != 0);
        
        blocks->Array[i]->ship = "X";
    }
}


void distroyBlocks(Blocks * blocks){
    free(blocks->Array);
    free(blocks);
}

void printBlocks(Blocks * blocks){
    for (int i = 0; i < blocks->nbrBlock; i++){
        gotoligcol(blocks->Array[i]->Position.x,blocks->Array[i]->Position.y);
        printf("\033[1;31m%c\033[0m",blocks->Array[i]->ship);
    }
}