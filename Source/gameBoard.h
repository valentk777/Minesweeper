#include "playerBoard.h"

class GameBoard : public Board 
{
private:
    int _bombCount;
    int _bombLocations[MAXBOMBS][2];
public:
    GameBoard(int side, int bomb);
    ~GameBoard() {};

    bool ifBomb(int row, int col);
    void relocateBomb(int row, int col);
    int countNearBombs(int row, int col);
    void addBombsLocations(PlayerBoard* playerBoard);
    bool isValid(int row, int col);

private:
    void generuokBombas();
};