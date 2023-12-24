#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "../header/protolib.h"
#include "../header/type.h"

Snoopy * createSnoopy(){
    Snoopy * snoopy = (Snoopy*)malloc(sizeof(Snoopy));
    snoopy->Object.Position.x = 12;
    snoopy->Object.Position.y = 32;
    return snoopy;
}

void initSnoopy(Snoopy * snoopy){
    gotoligcol(snoopy->Object.Position.x,snoopy->Object.Position.y);
    printf("\033[1;36m%c\033[0m",0x01);
}

void moveSnoopy(Snoopy * snoopy){
    
}