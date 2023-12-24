#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "../header/type.h"
#include "../header/protolib.h"


Grid* createGrid(){
    Grid* grid = (Grid*)malloc(sizeof(Grid)); 
    grid->Array = (char**)malloc(ROW * sizeof(char*));
    for (int i = 0; i < ROW; i++)
        grid->Array[i] = (char*)malloc(COL*sizeof(char));
    grid->Game = (Game*)malloc(sizeof(Game));
    return grid;
}

void initGrid(Grid* grid){
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            grid->Array[i][j] = ' ';
}

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

void gotoligcol( int lig, int col ){
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void positionSnoopy(){
    gotoligcol(1,4);
    printf("\033[1;36m%c\033[0m",0x01);
    getchar();
}

void distroyGrid(Grid* grid){
    for (int i = 0; i < ROW; i++)
        free(grid->Array[i]);
    free(grid->Array);
}

void playGame(Grid * grid){
    time_t start = time(NULL);
    srand(start);
    time_t end = start + grid->Param.time;
    initSnoopy(grid->Game->Snoopy);
    int key;
    while (1) {
        start = time(NULL);
        grid->Param.time = end - start;
        moveBall(grid->Game->Ball);
        gotoligcol(1,86);
        printf("\033[1;36mLife : %d",grid->Param.life);
        gotoligcol(3,86);
        printf("Birds : %d",grid->Param.birds);
        gotoligcol(5,86);
        printf("Time : %d",grid->Param.time);
        gotoligcol(7,86);
        printf("Level : %d\033[0m",grid->Param.level);
        
        if(kbhit()) key = getch();
        if (key == 72 && grid->Game->Snoopy->Object.Position.x > 2) {
            gotoligcol(grid->Game->Snoopy->Object.Position.x,grid->Game->Snoopy->Object.Position.y);
            printf(" ");
            grid->Game->Snoopy->Object.Position.x-=2;
            gotoligcol(grid->Game->Snoopy->Object.Position.x,grid->Game->Snoopy->Object.Position.y);
            printf("\033[1;36m%c\033[0m",0x01);
        }
        if (key == 80 && grid->Game->Snoopy->Object.Position.x < 20) {
            gotoligcol(grid->Game->Snoopy->Object.Position.x,grid->Game->Snoopy->Object.Position.y);
            printf(" ");
            grid->Game->Snoopy->Object.Position.x+=2;
            gotoligcol(grid->Game->Snoopy->Object.Position.x,grid->Game->Snoopy->Object.Position.y);
            printf("\033[1;36m%c\033[0m",0x01);
        }
        if (key == 75 && grid->Game->Snoopy->Object.Position.y > 4) {
            gotoligcol(grid->Game->Snoopy->Object.Position.x,grid->Game->Snoopy->Object.Position.y);
            printf(" ");
            grid->Game->Snoopy->Object.Position.y -= 4;
            gotoligcol(grid->Game->Snoopy->Object.Position.x,grid->Game->Snoopy->Object.Position.y);
            printf("\033[1;36m%c\033[0m",0x01);
        }
        if (key == 77 && grid->Game->Snoopy->Object.Position.y < 80) {
            gotoligcol(grid->Game->Snoopy->Object.Position.x,grid->Game->Snoopy->Object.Position.y);
            printf(" ");
            grid->Game->Snoopy->Object.Position.y=grid->Game->Snoopy->Object.Position.y+4;
            gotoligcol(grid->Game->Snoopy->Object.Position.x,grid->Game->Snoopy->Object.Position.y);
            printf("\033[1;36m%c\033[0m",0x01);
        }if (
            (grid->Game->Ball->Object.Position.x == grid->Game->Snoopy->Object.Position.x && 
            grid->Game->Ball->Object.Position.y == grid->Game->Snoopy->Object.Position.y)){
            grid->Param.life--;
        }if ((grid->Game->Blocks->Array[0]->Position.x == grid->Game->Snoopy->Object.Position.x&&
            grid->Game->Blocks->Array[0]->Position.y == grid->Game->Snoopy->Object.Position.y)){
            grid->Param.life--;
            grid->Game->Blocks->Array[0]->Position.x = 0;
            grid->Game->Blocks->Array[0]->Position.y = 0;
        }if ((grid->Game->Blocks->Array[1]->Position.x == grid->Game->Snoopy->Object.Position.x&&
            grid->Game->Blocks->Array[1]->Position.y == grid->Game->Snoopy->Object.Position.y)){
            grid->Param.life--;
            grid->Game->Blocks->Array[1]->Position.x = 0;
            grid->Game->Blocks->Array[1]->Position.y = 0;
        }if ((grid->Game->Blocks->Array[2]->Position.x == grid->Game->Snoopy->Object.Position.x&&
            grid->Game->Blocks->Array[2]->Position.y == grid->Game->Snoopy->Object.Position.y)){
            grid->Param.life--;
            grid->Game->Blocks->Array[2]->Position.x = 0;
            grid->Game->Blocks->Array[2]->Position.y = 0;
        }if ((grid->Game->Blocks->Array[3]->Position.x == grid->Game->Snoopy->Object.Position.x&&
            grid->Game->Blocks->Array[3]->Position.y == grid->Game->Snoopy->Object.Position.y)){
            grid->Param.life--;
            grid->Game->Blocks->Array[3]->Position.x = 0;
            grid->Game->Blocks->Array[3]->Position.y = 0;
        }if ((grid->Game->Blocks->Array[4]->Position.x == grid->Game->Snoopy->Object.Position.x&&
            grid->Game->Blocks->Array[4]->Position.y == grid->Game->Snoopy->Object.Position.y)){
            grid->Param.life--;
            grid->Game->Blocks->Array[4]->Position.x = 0;
            grid->Game->Blocks->Array[4]->Position.y = 0;
        }if ((grid->Game->Blocks->Array[5]->Position.x == grid->Game->Snoopy->Object.Position.x&&
            grid->Game->Blocks->Array[5]->Position.y == grid->Game->Snoopy->Object.Position.y)){
            grid->Param.life--;
            grid->Game->Blocks->Array[5]->Position.x = 0;
            grid->Game->Blocks->Array[5]->Position.y = 0;
        }if ((grid->Game->Blocks->Array[6]->Position.x == grid->Game->Snoopy->Object.Position.x&&
            grid->Game->Blocks->Array[6]->Position.y == grid->Game->Snoopy->Object.Position.y)){
            grid->Param.life--;
            grid->Game->Blocks->Array[6]->Position.x = 0;
            grid->Game->Blocks->Array[6]->Position.y = 0;
        }if ((grid->Game->Blocks->Array[7]->Position.x == grid->Game->Snoopy->Object.Position.x&& 
            grid->Game->Blocks->Array[7]->Position.y == grid->Game->Snoopy->Object.Position.y)){
            grid->Param.life--;
            grid->Game->Blocks->Array[7]->Position.x = 0;
            grid->Game->Blocks->Array[7]->Position.y = 0;
        }if ((grid->Game->Blocks->Array[8]->Position.x == grid->Game->Snoopy->Object.Position.x&&
            grid->Game->Blocks->Array[8]->Position.y == grid->Game->Snoopy->Object.Position.y)){
            grid->Param.life--;
            grid->Game->Blocks->Array[8]->Position.x = 0;
            grid->Game->Blocks->Array[8]->Position.y = 0;
        }if ((grid->Game->Blocks->Array[9]->Position.x == grid->Game->Snoopy->Object.Position.x&& 
            grid->Game->Blocks->Array[9]->Position.y == grid->Game->Snoopy->Object.Position.y)){
            grid->Param.life--;
            grid->Game->Blocks->Array[9]->Position.x = 0;
            grid->Game->Blocks->Array[9]->Position.y = 0;    
        }
        if (!grid->Param.life || start == end)
        {
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
            break;
        }if (grid->Game->Snoopy->Object.Position.x == grid->Game->Birds->Bird_1.Position.x && 
            grid->Game->Snoopy->Object.Position.y == grid->Game->Birds->Bird_1.Position.y){
            grid->Param.birds++;
            grid->Game->Birds->Bird_4.ship = " ";
            grid->Game->Birds->Bird_1.Position.x = 0;
            grid->Game->Birds->Bird_1.Position.y = 0;
        }if (grid->Game->Snoopy->Object.Position.x == grid->Game->Birds->Bird_2.Position.x &&
            grid->Game->Snoopy->Object.Position.y == grid->Game->Birds->Bird_2.Position.y){
            grid->Param.birds++;
            grid->Game->Birds->Bird_4.ship = " ";
            grid->Game->Birds->Bird_2.Position.x = 0;
            grid->Game->Birds->Bird_2.Position.y = 0;
        }if (grid->Game->Snoopy->Object.Position.x == grid->Game->Birds->Bird_3.Position.x &&
            grid->Game->Snoopy->Object.Position.y == grid->Game->Birds->Bird_3.Position.y){
            grid->Param.birds++;
            grid->Game->Birds->Bird_4.ship = " ";
            grid->Game->Birds->Bird_3.Position.x = 0;
            grid->Game->Birds->Bird_3.Position.y = 0;
        }if (grid->Game->Snoopy->Object.Position.x == grid->Game->Birds->Bird_4.Position.x &&
            grid->Game->Snoopy->Object.Position.y == grid->Game->Birds->Bird_4.Position.y){
            grid->Param.birds++;
            grid->Game->Birds->Bird_4.ship = " ";
            grid->Game->Birds->Bird_4.Position.x = 0;
            grid->Game->Birds->Bird_4.Position.y = 0;
        }if (grid->Param.birds == 4){
            system("clear");
            printf("\n\n\033[1;33m\"   :) You Win !   \"\033[0m\n\n");
            printf("\033[1;36m+---------------+\n");
            printf("| Life : %d\t|\n",grid->Param.life);
            printf("| Birds : %d\t|\n",grid->Param.birds);
            printf("| Time : %d\t|\n",grid->Param.time);
            printf("| Level : %d\t|\n",grid->Param.level);
            printf("+---------------+\033[0m\n\n");
            printf("--> [ move to menu press \033[1;33m\"Enter\"\033[0m ] <--\n\n");
            while (getch() != 13);
            system("clear");
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
