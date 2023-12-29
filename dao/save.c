#include "../header/protolib.h"

/**
 * @brief Sauvegarde du jeu
 * 
 * @param Grid* 
 */
void saveGame(Grid* grid) {
    FILE* file = fopen(PATH, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(file, "%d\n", grid->Game->Snoopy->Object.Position.x);
    fprintf(file, "%d\n", grid->Game->Snoopy->Object.Position.y);

    fprintf(file, "%d\n", grid->Game->Ball->Object.Position.x);
    fprintf(file, "%d\n", grid->Game->Ball->Object.Position.y);
    fprintf(file, "%d\n", grid->Game->Ball->direction);

    fprintf(file, "%d\n", grid->Game->Birds->Bird_1.Position.x);
    fprintf(file, "%d\n", grid->Game->Birds->Bird_1.Position.y);
    fprintf(file, " %c\n", grid->Game->Birds->Bird_1.ship);

    fprintf(file, "%d\n", grid->Game->Birds->Bird_2.Position.x);
    fprintf(file, "%d\n", grid->Game->Birds->Bird_2.Position.y);
    fprintf(file, " %c\n", grid->Game->Birds->Bird_2.ship);

    fprintf(file, "%d\n", grid->Game->Birds->Bird_3.Position.x);
    fprintf(file, "%d\n", grid->Game->Birds->Bird_3.Position.y);
    fprintf(file, " %c\n", grid->Game->Birds->Bird_3.ship);

    fprintf(file, "%d\n", grid->Game->Birds->Bird_4.Position.x);
    fprintf(file, "%d\n", grid->Game->Birds->Bird_4.Position.y);
    fprintf(file, " %c\n", grid->Game->Birds->Bird_4.ship);

    fprintf(file, "%d\n", grid->Param.birds);
    fprintf(file, "%d\n", grid->Param.life);
    fprintf(file, "%d\n", grid->Param.time);
    fprintf(file, "%d\n", grid->Param.level);

    fclose(file);
}