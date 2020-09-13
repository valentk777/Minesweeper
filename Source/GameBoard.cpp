#include "stdafx.h"
#include "gameBoard.h"

GameBoard::GameBoard(int side, int bomb)
{
    _side = side;
    _bombCount = bomb;

    srand(time(NULL));

    for (int i = 0; i < side; i++)
        for (int j = 0; j < side; j++)
            _board[i][j] = '-';

    generuokBombas();
}

void GameBoard::generuokBombas() 
{
    bool zymes[MAXSIZE * MAXSIZE];

    memset(zymes, false, sizeof(zymes));

    for (int i = 0; i < _bombCount; )
    {
        int random = rand() % (_side * _side);
        int x = random / _side;
        int y = random % _side;

        if (zymes[random] == false)
        {
            _bombLocations[i][0] = x;
            _bombLocations[i][1] = y;

            _board[_bombLocations[i][0]][_bombLocations[i][1]] = '*';
            zymes[random] = true;
            i++;
        }
    }
}

void GameBoard::relocateBomb(int row, int col) 
{
    for (int i = 0; i < _side; i++)
    {
        for (int j = 0; j < _side; j++)
        {
            if (_board[i][j] == '*')
                continue;

            _board[i][j] = '*';
            _board[row][col] = '-';
            for (int k = 0; k < MAXBOMBS; k++)
                if (_bombLocations[k][0] == row && _bombLocations[k][1] == col)
                {
                    _bombLocations[k][0] = i;
                    _bombLocations[k][1] = j;
                    break;
                }

            return;
        }
    }
    return;
}

bool GameBoard::ifBomb(int row, int col) 
{
    return _board[row][col] == '*';
}

bool GameBoard::isValid(int row, int col) 
{
    return (row >= 0) && (row < _side) && (col >= 0) && (col < _side);
}

int GameBoard::countNearBombs(int row, int col)
{
    int count = 0;

    for (int i = -1; i < 2; i++) 
    {
        for (int j = -1; j < 2; j++) 
        {
            if (!isValid(row + i, col + j))
                continue;

            if (row + i == row && col + j == col)
                continue;

            if (ifBomb(row + i, col + j))
                count++;
        }
    };

    return count;
}

void GameBoard::addBombsLocations(PlayerBoard* playerBoard)
{
    for (int i = 0; i < _bombCount; i++)
        playerBoard->writeValue(_bombLocations[i][0], _bombLocations[i][1], '*');
}