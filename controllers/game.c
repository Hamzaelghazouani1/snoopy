#include <stdio.h>
#include <stdlib.h>
#include "../header/protolib.h"
#include "../header/type.h"

void startNewGame(void) {
    Grid grid = createGrid();
    initGrid(grid);
    printGrid(grid);
}