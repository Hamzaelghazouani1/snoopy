#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "../header/protolib.h"


/**
 * @brief Affiche l'ecran de jeu avec les elements du decor
 * 
 * @param grid 
 * @return void
 */
void printGrid(Grid* grid){
    system("clear");
    printf("\033[1;32m _");
    for (int j = 0; j < COL; j++) printf("____");
    printf("__\n");

    printf("|##");
    for (int j = 0; j < COL; j++) printf("####");
    printf("#|\033[0m\n");
    
    for (int i = 0; i < ROW; i++){
        printf("\033[1;32m|#|\033[0m");
        for (int j = 0; j < COL; j++){
            printf(" %c",grid->Array[i][j]);
            printf(" |");
        }
        printf("\033[1;32m#|\033[0m\n");
        printf("\033[1;32m|#|\033[0m");
        for (int j = 0; j < COL; j++){
            printf("---");
            printf("|");
        }
        printf("\033[1;32m#|\033[0m\n");
    }
    printf("\033[1;32m|##");
    for (int j = 0; j < COL; j++) printf("####");
    printf("#|\033[0m\n");
}


void printSettings(Grid* grid){
        moveBall(grid->Game->Ball);
        gotoligcol(1,86);
        printf("\033[1;36mLife : %d",grid->Param.life);
        gotoligcol(3,86);
        printf("Birds : %d",grid->Param.birds);
        gotoligcol(5,86);
        printf("Time : %d",grid->Param.time);
        gotoligcol(7,86);
        printf("Level : %d\033[0m",grid->Param.level);
}