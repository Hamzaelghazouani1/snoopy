#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../header/protolib.h"

/**
 * @brief Affiche l'ecran win
 * 
 * @param Grid*
 */
void printWin(Grid* grid){
    system("clear");
    printf("\n\n\033[1;32m\"   :)  You Win !    \"\033[0m\n\n");
    printf("\033[1;32m+---------------+\n");
    printf("| Life : %d\t|\n",grid->Param.life);
    printf("| Birds : %d\t|\n",grid->Param.birds);
    printf("| Time : %d\t|\n",grid->Param.time);
    printf("| Level : %d\t|\n",grid->Param.level);
    printf("+---------------+\033[0m\n\n");
    printf("--> [ move to menu press \033[1;33m\"Enter\"\033[0m ] <--\n\n");
    while (getch() != 13);
    system("clear");
}

/**
 * @brief Affiche l'ecran game over
 * 
 * @param Grid*
 */
void printGameOver(Grid* grid){
    system("clear");
    printf("\n\n\033[1;31m\"   :(  Game Over !    \"\033[0m\n\n");
    printf("\033[1;31m+---------------+\n");
    printf("| Life : %d\t|\n",grid->Param.life);
    printf("| Birds : %d\t|\n",grid->Param.birds);
    printf("| Time : %d\t|\n",grid->Param.time);
    printf("| Level : %d\t|\n",grid->Param.level);
    printf("+---------------+\033[0m\n\n");
    printf("--> [ move to menu press \033[1;33m\"Enter\"\033[0m ] <--\n\n");
    while (getch() != 13);
    system("clear");
}