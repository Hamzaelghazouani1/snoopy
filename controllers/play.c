#include <windows.h>
#include <conio.h>
#include <time.h>
#include "../header/protolib.h"

/**
 * @brief Lancemenet du jeu avec les parametres definis par le type Game (resumeGame, startNewGame,...)
 * 
 * @param Grid* 
 */
void playGame(Grid * grid){
    time_t start = time(NULL);
    srand(start);
    time_t end = start + grid->Param.time;
    initSnoopy(grid->Game->Snoopy);
    int key;
    
    while (1) {
        start = time(NULL);
        grid->Param.time = end - start;
        printSettings(grid);
        if(kbhit()) key = getch();
        moveSnoopy(grid,key);
        downLife(grid);
        if (!grid->Param.life || start == end) {
            printGameOver(grid);
            break;
        }
        removeBird(grid);
        if (grid->Param.birds == 4) {
            printWin(grid);
            break;
        }
        if (key == 113) {
            system("clear");
            break;
        }   
        if (key == 115) {
            system("clear");
            saveGame(grid);
            printf("\n\n\033[1;33m\"   :) Game Saved !   \"\033[0m\n\n");
            break;
        }
        key = 0;
        Sleep(60);
    }
}
