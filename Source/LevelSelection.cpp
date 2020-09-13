#include "stdafx.h"
#include "levelSelection.h"

using namespace std;

pair<int, int> selectLevelOrExit()
{
    int level;

    printf("Select level\n");
    printf("0 - Exit a game\n");
    printf("1 - Easy (9 x 9 board with 10 mines)\n");
    printf("2 - Middle (16 x 16 board with 40 mines)\n");
    printf("3 - Hard (24 x 24 board with 99 mines)\n");

    scanf_s("%d", &level);

    if (level == 0)
        exit(0);
    if (level == 1)
        return pair<int, int> {9, 10};

    if (level == 2)
        return pair<int, int> {16, 40};

    if (level == 3)
        return pair<int, int> {24, 99};
}
