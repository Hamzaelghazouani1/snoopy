#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
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
    printf("%c",0x03);
    getchar();
}

void distroyGrid(Grid grid){
    for (int i = 0; i < ROW; i++)
        free(grid.Array[i]);
    free(grid.Array);
}

void btnDetection(Grid grid){
    int x = 12, y = 36;
    int controlle = 1;
    int xb = 14, yb = 76;
    int up = 0;
    gotoligcol(x,y);
    printf("%c",0x03);
    gotoligcol(xb,yb);
    printf("%c",0xAB);
    while (1) {
        controlle = getch();
        if(!up && yb<80){
            gotoligcol(xb,yb);
            printf(" ");
            xb=xb+2;
            yb=yb+4;
            gotoligcol(xb,yb);
            printf("%c",0xAB);
        }else if(up && (xb > 2)){
            gotoligcol(xb,yb);
            printf(" ");            
            xb=xb-2;
            yb=yb-4;
            gotoligcol(xb,yb);
            printf("%c",0xAB);
        }else{
            up = !up;
        }

        if (controlle == 72 && x > 2) {
            // printf("Bouton Haut cliqué\n");
            gotoligcol(x,y);
            printf(" ");
            x=x-2;
            gotoligcol(x,y);
            printf("%c",0x03);
        }
        if (controlle == 80 && x < 20) {
            // printf("Bouton Bas cliqué\n");
            gotoligcol(x,y);
            printf(" ");
            x=x+2;
            gotoligcol(x,y);
            printf("%c",0x03);
        }
        if (controlle == 75 && y > 4) {
            // printf("Bouton Gauche cliqué\n");
            gotoligcol(x,y);
            printf(" ");
            y=y-4;
            gotoligcol(x,y);
            printf("%c",0x03);
        }
        if (controlle == 77 && y < 80) {
            // printf("Bouton Droit cliqué\n");
            gotoligcol(x,y);
            printf(" ");
            y=y+4;
            gotoligcol(x,y);
            printf("%c",0x03);
        }if (controlle == 113) {
            // printf("Bouton Droit cliqué\n");
            system("clear");
            break;
        }
        if (controlle == 115) {
            // printf("Bouton Droit cliqué\n");
            break;
        }
        Sleep(120);
        continue;
    }
}


Blocks* createBlocks(int nbrBlock) {
    Blocks* blocks = (Blocks*)malloc(sizeof(Blocks));
    blocks->nbrBlock = nbrBlock;
    blocks->Array = (Object**)malloc(nbrBlock * sizeof(Object*));
    for (int i = 0; i < nbrBlock; i++) {
        blocks->Array[i] = (Object*)malloc(sizeof(Object));
    }
    return blocks;
}


void initBlocks(Blocks* blocks) {
    for (int i = 0; i < blocks->nbrBlock; i++) {
        do {
            blocks->Array[i]->Position.x = rand() % 20;
        } while (blocks->Array[i]->Position.x <= 2 || blocks->Array[i]->Position.x % 2 != 0);

        do {
            blocks->Array[i]->Position.y = rand() % 80;
        } while (blocks->Array[i]->Position.y <= 2 || blocks->Array[i]->Position.y % 4 != 0);
        
        blocks->Array[i]->ship = "0x04";
    }
}


void distroyBlocks(Blocks * blocks){
    free(blocks->Array);
    free(blocks);
}

void printBlocks(Blocks * blocks){
    for (int i = 0; i < blocks->nbrBlock; i++){
        gotoligcol(blocks->Array[i]->Position.x,blocks->Array[i]->Position.y);
        printf("%c",blocks->Array[i]->ship);
    }
}