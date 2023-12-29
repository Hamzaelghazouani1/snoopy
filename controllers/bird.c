#include "../header/protolib.h"

/**
 * @brief Creation des oiseaux
 * 
 * @return Birds* 
 */
Birds * createBirds(void){
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

/**
 * @brief Comparaison de la position de Snoopy et des oiseaux
 * 
 * @param Grid* 
 */
void removeBird(Grid* grid){
        if (grid->Game->Snoopy->Object.Position.x == grid->Game->Birds->Bird_1.Position.x && 
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
        }
}

/**
 * @brief Distuction des oiseaux
 * 
 * @param Birds* 
 */
void distroyBirds(Birds * birds){
    free(birds);
}