#include <stdio.h>
#include <stdlib.h>
#include "../header/protolib.h"
#include "../header/type.h"

void startNewGame(void) {
    Grid grid = createGrid();
    initGrid(grid);
    Blocks * blocks = createBlocks(10);
    initBlocks(blocks);
    printGrid(grid);
    printBlocks(blocks);
    Birds * birds = CreateBirds();
    printBirds(birds);
    btnDetection(grid);
}