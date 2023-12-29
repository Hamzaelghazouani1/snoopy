#include <stdio.h>
#include "../header/protolib.h"

/**
 * @brief Affiche les oiseaux sur la grille
 * 
 * @param Birds* 
 */
void printBirds(Birds * birds){
    gotoligcol(birds->Bird_1.Position.x,birds->Bird_1.Position.y);
    printf("\033[1;34m%c\033[0m",0xAF);
    gotoligcol(birds->Bird_2.Position.x,birds->Bird_2.Position.y);
    printf("\033[1;34m%c\033[0m",0xAF);
    gotoligcol(birds->Bird_3.Position.x,birds->Bird_3.Position.y);
    printf("\033[1;34m%c\033[0m",0xAF);
    gotoligcol(birds->Bird_4.Position.x,birds->Bird_4.Position.y);
    printf("\033[1;34m%c\033[0m",0xAF);
}