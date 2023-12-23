#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../header/type.h"
#include "../header/protolib.h"


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
            printf(" %c",grid.Array[i][j]);
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
    printf("%c",0x01);
    getchar();
}

void distroyGrid(Grid grid){
    for (int i = 0; i < ROW; i++)
        free(grid.Array[i]);
    free(grid.Array);
}

void btnDetection(Grid grid){
    Ball * ball = createBall();
    Snoopy * snoopy = createSnoopy();
    initSnoopy(snoopy);
    while (1) {
        int key;
        moveBall(ball);
        key = getch();
        if (key == 72 && snoopy->Object.Position.x > 2) {
            gotoligcol(snoopy->Object.Position.x,snoopy->Object.Position.y);
            printf(" ");
            snoopy->Object.Position.x-=2;
            gotoligcol(snoopy->Object.Position.x,snoopy->Object.Position.y);
            printf("%c",0x01);
        }
        if (key == 80 && snoopy->Object.Position.x < 20) {
            gotoligcol(snoopy->Object.Position.x,snoopy->Object.Position.y);
            printf(" ");
            snoopy->Object.Position.x+=2;
            gotoligcol(snoopy->Object.Position.x,snoopy->Object.Position.y);
            printf("%c",0x01);
        }
        if (key == 75 && snoopy->Object.Position.y > 4) {
            gotoligcol(snoopy->Object.Position.x,snoopy->Object.Position.y);
            printf(" ");
            snoopy->Object.Position.y -= 4;
            gotoligcol(snoopy->Object.Position.x,snoopy->Object.Position.y);
            printf("%c",0x01);
        }
        if (key == 77 && snoopy->Object.Position.y < 80) {
            gotoligcol(snoopy->Object.Position.x,snoopy->Object.Position.y);
            printf(" ");
            snoopy->Object.Position.y=snoopy->Object.Position.y+4;
            gotoligcol(snoopy->Object.Position.x,snoopy->Object.Position.y);
            printf("%c",0x01);
        }if (key == 113) {
            system("clear");
            break;
        }
        if (key == 115) {
            break;
        }
        Sleep(120);
    }
}
