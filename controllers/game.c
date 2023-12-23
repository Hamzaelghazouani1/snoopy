#include <stdio.h>
#include <stdlib.h>
#include "../header/protolib.h"
#include "../header/type.h"

void startNewGame(void) {
    Grid grid = createGrid();
    initGrid(grid);
    grid.Game->Blocks = createBlocks(10);
    initBlocks(grid.Game->Blocks);
    printGrid(grid);
    printBlocks(grid.Game->Blocks);
    grid.Game->Birds = CreateBirds();
    printBirds(grid.Game->Birds);
    playGame(grid);
}