#include "../header/protolib.h"

/**
 * @brief Creation des blocs dans la memoire
 * 
 * @param nbrBlock 
 * @return Blocks* 
 */
Blocks* createBlocks(int nbrBlock) {
    Blocks* blocks = (Blocks*)malloc(sizeof(Blocks));
    blocks->nbrBlock = nbrBlock;
    blocks->Array = (Object**)malloc(nbrBlock * sizeof(Object*));
    for (int i = 0; i < nbrBlock; i++) 
        blocks->Array[i] = (Object*)malloc(sizeof(Object));
    return blocks;
}

/**
 * @brief initialisation des blocs dans la grille de jeu random
 * 
 * @param Blocks*
 */
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

/**
 * @brief distruction des blocs dans la memoire
 * 
 * @param blocks 
 */
void distroyBlocks(Blocks * blocks){
    free(blocks->Array);
    free(blocks);
}