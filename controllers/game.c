#include "../header/protolib.h"

/**
 * @brief Lancemenet du jeu avec les parametres par defaut du premier niveau
 * 
 */
void startNewGame(void) {
    Grid * grid = createGrid();
    initGrid(grid);
    grid->Game->Blocks = createBlocks(10);
    initBlocks(grid->Game->Blocks);
    printGrid(grid);
    printBlocks(grid->Game->Blocks);
    grid->Game->Birds = createBirds();
    printBirds(grid->Game->Birds);
    grid->Game->Snoopy = createSnoopy();
    grid->Game->Ball = createBall();
    grid->Param.life = 3;
    grid->Param.birds = 0;
    grid->Param.time = 30;
    grid->Param.level = 1;
    playGame(grid);
}

/**
 * @brief lancemenet du jeu avec les parametres sauvegardes
 * 
 */
void resumeGame(void) {
    Grid * grid = createGrid();
    initGrid(grid);
    grid->Game->Blocks = createBlocks(10);
    initBlocks(grid->Game->Blocks);
    printGrid(grid);
    printBlocks(grid->Game->Blocks);
    grid->Game->Birds = createBirds();
    grid->Game->Snoopy = createSnoopy();
    grid->Game->Ball = createBall();
    loadGame(grid);
    printBirds(grid->Game->Birds);
    playGame(grid);
}

