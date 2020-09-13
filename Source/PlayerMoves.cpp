#include "stdafx.h"
#include "gameBoard.h"
#include "playerMoves.h"

void playerMove(int* x, int* y)
{
    printf("Enter your move, (row, col) -> ");
    scanf_s("%d %d", x, y);
    return;
}

bool executePlayerMove(GameBoard* mainBoard, PlayerBoard* playerBoard, int row, int col, int* movesLeft)
{
    if (!playerBoard->isEmpty(row, col))
        return false;

    int i, j;

    // when player loose
    if (mainBoard->ifBomb(row, col))
    {
        mainBoard->addBombsLocations(playerBoard);
        playerBoard->printGameBoard();
        printf("\nYou missed!\n");
        return true;
    }

    int count = mainBoard->countNearBombs(row, col);
    (*movesLeft)--;

    playerBoard->writeValue(row, col, count + '0');

    if (count)
        return false;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (!mainBoard->isValid(row + i, col + j))
                continue;

            if (row + i == row && col + j == col)
                continue;

            if (!mainBoard->ifBomb(row + i, col + j))
                executePlayerMove(mainBoard, playerBoard, row + i, col + j, movesLeft);
        }
    };

    return false;
}