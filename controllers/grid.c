#include <stdio.h>
#include <stdlib.h>
#include "../header/type.h"


Grid createGrid(){
    Grid grid; 
    grid.Array = (char**)malloc(ROW * sizeof(char*));
    for (int i = 0; i < ROW; i++)
        grid.Array[i] = (char*)malloc(COL*sizeof(char));
    return grid;
}

void initGrid(Grid grid){
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            grid.Array[i][j] = ' ';
}

void printGrid(Grid grid){
    printf(" _");
    for (int j = 0; j < COL; j++) printf("____");
    printf("__\n");

    printf("|##");
    for (int j = 0; j < COL; j++) printf("####");
    printf("#|\n");
    
    for (int i = 0; i < ROW; i++){
        printf("|#|");
        for (int j = 0; j < COL; j++){
            printf(" %c",grid.Array[i][j]);
            printf(" |");
        }
        printf("#|\n");
        printf("|#|");
        for (int j = 0; j < COL; j++){
            printf("---");
            printf("|");
        }
        printf("#|\n");
    }
    printf("|##");
    for (int j = 0; j < COL; j++) printf("####");
    printf("#|\n");
}

void distroyGrid(Grid grid){
    for (int i = 0; i < ROW; i++)
        free(grid.Array[i]);
    free(grid.Array);
}