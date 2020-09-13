#include "board.h"

class PlayerBoard : public Board
{
public:
    PlayerBoard(int size);
    ~PlayerBoard() {};

    void printGameBoard();
    bool isEmpty(int row, int col);
    void writeValue(int row, int col, char value);
};