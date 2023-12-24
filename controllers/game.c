#include <stdio.h>
#include <stdlib.h>
#include "../header/protolib.h"
#include "../header/type.h"

void startNewGame(void) {
    Grid * grid = createGrid();
    initGrid(grid);
    grid->Game->Blocks = createBlocks(10);
    initBlocks(grid->Game->Blocks);
    printGrid(grid);
    printBlocks(grid->Game->Blocks);
    grid->Game->Birds = CreateBirds();
    printBirds(grid->Game->Birds);
    grid->Game->Snoopy = createSnoopy();
    grid->Game->Ball = createBall();
    grid->Param.life = 3;
    grid->Param.birds = 0;
    grid->Param.time = 30;
    grid->Param.level = 1;
    playGame(grid);
}

void resumeGame(void) {
    Grid * grid = createGrid();
    initGrid(grid);
    grid->Game->Blocks = createBlocks(10);
    initBlocks(grid->Game->Blocks);
    printGrid(grid);
    printBlocks(grid->Game->Blocks);
    grid->Game->Birds = CreateBirds();
    grid->Game->Snoopy = createSnoopy();
    grid->Game->Ball = createBall();
    loadGame(grid);
    printBirds(grid->Game->Birds);
    playGame(grid);
}

void saveGame(Grid* grid) {
    FILE* file = fopen("games/save.txt", "w");
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
    fscanf(file, "%c", &grid->Game->Birds->Bird_1.ship);

    fscanf(file, "%d", &grid->Game->Birds->Bird_2.Position.x);
    fscanf(file, "%d", &grid->Game->Birds->Bird_2.Position.y);
    fscanf(file, "%c", &grid->Game->Birds->Bird_2.ship);

    fscanf(file, "%d", &grid->Game->Birds->Bird_3.Position.x);
    fscanf(file, "%d", &grid->Game->Birds->Bird_3.Position.y);
    fscanf(file, "%c", &grid->Game->Birds->Bird_3.ship);

    fscanf(file, "%d", &grid->Game->Birds->Bird_4.Position.x);
    fscanf(file, "%d", &grid->Game->Birds->Bird_4.Position.y);
    fscanf(file, "%c", &grid->Game->Birds->Bird_4.ship);

    fscanf(file, "%d", &grid->Param.birds);
    fscanf(file, "%d", &grid->Param.life);
    fscanf(file, "%d", &grid->Param.time);
    fscanf(file, "%d", &grid->Param.level);
    printf("%d", grid->Param.time);

    fclose(file);
}