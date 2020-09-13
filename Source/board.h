#define MAXSIZE 25
#define MAXBOMBS 99
#define MOVES 526 // (25 * 25 - 99)

class Board
{
protected:
    int _side;
    char _board[MAXSIZE][MAXSIZE];
};