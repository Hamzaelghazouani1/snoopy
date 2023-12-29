#include <windows.h>
#include <conio.h>
#include <time.h>
#include "../header/protolib.h"

/**
 * @brief Creer un nouveau grid de jeu
 * 
 * @param void
 * @return Grid*
 */
Grid* createGrid(void){
    Grid* grid = (Grid*)malloc(sizeof(Grid)); 
    grid->Array = (char**)malloc(ROW * sizeof(char*));
    for (int i = 0; i < ROW; i++)
        grid->Array[i] = (char*)malloc(COL*sizeof(char));
    grid->Game = (Game*)malloc(sizeof(Game));
    return grid;
}

/**
 * @brief Initialise le grid de jeu
 * 
 * @param Grid* 
 * @return void
 */
void initGrid(Grid* grid){
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            grid->Array[i][j] = ' ';
}

/**
 * @brief Supprime le grid de jeu
 * 
 * @param Grid*
 */
void distroyGrid(Grid* grid){
    for (int i = 0; i < ROW; i++)
        free(grid->Array[i]);
    free(grid->Array);
}

/**
 * @brief translate les coordonnées du objet en coordonnées du grid
 * 
 * @param lig 
 * @param col 
 */
void gotoligcol( int lig, int col ){
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}