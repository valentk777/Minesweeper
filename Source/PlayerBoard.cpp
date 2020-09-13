#include "stdafx.h"
#include "playerBoard.h"

PlayerBoard::PlayerBoard(int size) 
{
    _side = size;

    srand(time(NULL));

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            _board[i][j] = '-';
}

void PlayerBoard::printGameBoard()
{
    int i, j;

    printf("    ");

    for (i = 0; i < _side; i++)
        printf("%d ", i);

    printf("\n\n");

    for (i = 0; i < _side; i++)
    {
        printf("%d   ", i);

        for (j = 0; j < _side; j++)
            printf("%c ", _board[i][j]);
        printf("\n");
    }
    return;
}

bool PlayerBoard::isEmpty(int row, int col) 
{
    return _board[row][col] == '-';
}

void PlayerBoard::writeValue(int row, int col, char value)
{
    _board[row][col] = value;
}