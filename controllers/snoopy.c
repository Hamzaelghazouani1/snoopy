#include "../header/protolib.h"

/**
 * @brief Creation de Snoopy
 * 
 * @return Snoopy* 
 */
Snoopy * createSnoopy(void){
    Snoopy * snoopy = (Snoopy*)malloc(sizeof(Snoopy));
    snoopy->Object.Position.x = 12;
    snoopy->Object.Position.y = 32;
    return snoopy;
}

/**
 * @brief Initialisation de Snoopy dans la grille
 * 
 * @param Snoopy* 
 */
void initSnoopy(Snoopy * snoopy){
    gotoligcol(snoopy->Object.Position.x,snoopy->Object.Position.y);
    printf("\033[1;36m%c\033[0m",0x01);
}


/**
 * @brief Deplacement de Snoopy sur la grille
 * 
 * @param Grid* 
 * @param key 
 */
void moveSnoopy(Grid* grid,int key){
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
        }
}


/**
 * @brief Dicrementation de la vie de Snoopy
 * 
 * @param Grid*
 */
void downLife(Grid* grid){
        if ((grid->Game->Ball->Object.Position.x == grid->Game->Snoopy->Object.Position.x && 
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
}