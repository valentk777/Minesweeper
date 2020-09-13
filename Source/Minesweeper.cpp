#include "stdafx.h"
#include "gameBoard.h"
#include "playerMoves.h"
#include "levelSelection.h"

int main()
{
    std::pair<int, int> p = selectLevelOrExit();

    bool end = false;
    int x, y;
    int movesLeft = p.first * p.first - p.second;

    GameBoard mainBoard(p.first, p.second);
    PlayerBoard myBoard(p.first);

    int currentMove = 0;
    while (!end)
    {
        printf("Current game board: \n");
        myBoard.printGameBoard();
        playerMove(&x, &y);

        // If first shot to mine, then continue a game
        if (currentMove == 0)
            // Regenerate board value
            if (mainBoard.ifBomb(x, y))
                mainBoard.relocateBomb(x, y);

        currentMove++;

        end = executePlayerMove(&mainBoard, &myBoard, x, y, &movesLeft);

        if (!end && movesLeft == 0)
        {
            printf("\nYou won!!!\n");
            end = true;
        }
    }
    return 0;
}