#include <stdio.h>
#include "../header/protolib.h"

void printBlocks(Blocks * blocks){
    for (int i = 0; i < blocks->nbrBlock; i++){
        gotoligcol(blocks->Array[i]->Position.x,blocks->Array[i]->Position.y);
        printf("\033[1;31mX\033[0m");
    }
}