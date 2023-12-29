#include "../header/protolib.h"

/**
 * @brief Chargement du jeu
 * 
 * @param Grid* 
 */
void loadGame(Grid* grid) {
    FILE* file = fopen("games/save.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fscanf(file, "%d", &grid->Game->Snoopy->Object.Position.x);
    fscanf(file, "%d", &grid->Game->Snoopy->Object.Position.y);

    fscanf(file, "%d", &grid->Game->Ball->Object.Position.x);
    fscanf(file, "%d", &grid->Game->Ball->Object.Position.y);
    fscanf(file, "%d", &grid->Game->Ball->direction);

    fscanf(file, "%d", &grid->Game->Birds->Bird_1.Position.x);
    fscanf(file, "%d", &grid->Game->Birds->Bird_1.Position.y);
    fscanf(file, " %c", &grid->Game->Birds->Bird_1.ship);

    fscanf(file, "%d", &grid->Game->Birds->Bird_2.Position.x);
    fscanf(file, "%d", &grid->Game->Birds->Bird_2.Position.y);
    fscanf(file, " %c", &grid->Game->Birds->Bird_2.ship);

    fscanf(file, "%d", &grid->Game->Birds->Bird_3.Position.x);
    fscanf(file, "%d", &grid->Game->Birds->Bird_3.Position.y);
    fscanf(file, " %c", &grid->Game->Birds->Bird_3.ship);

    fscanf(file, "%d", &grid->Game->Birds->Bird_4.Position.x);
    fscanf(file, "%d", &grid->Game->Birds->Bird_4.Position.y);
    fscanf(file, " %c", &grid->Game->Birds->Bird_4.ship);

    fscanf(file, "%d", &grid->Param.birds);
    fscanf(file, "%d", &grid->Param.life);
    fscanf(file, "%d", &grid->Param.time);
    fscanf(file, "%d", &grid->Param.level);

    fclose(file);
}