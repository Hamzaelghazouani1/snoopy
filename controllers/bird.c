#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../header/type.h"
#include "../header/protolib.h"

Birds * CreateBirds(){
    Birds * birds = (Birds*)malloc(sizeof(Birds));
    birds->Bird_1.Position.x = 2;
    birds->Bird_1.Position.y = 4;
    birds->Bird_1.ship = "0xAF";
    birds->Bird_2.Position.x = 2;
    birds->Bird_2.Position.y = 80;
    birds->Bird_2.ship = "0xAF";
    birds->Bird_3.Position.x = 20;
    birds->Bird_3.Position.y = 4;
    birds->Bird_3.ship = "0xAF";
    birds->Bird_4.Position.x = 20;
    birds->Bird_4.Position.y = 80;
    birds->Bird_4.ship = "0xAF";
    return birds;
}

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