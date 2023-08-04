
#include "gameMenu.h"

void startGame()
{
    int i, j, score;
    char name[30];
    clearScreen();
    printf("Enter your name : ");
    scanf("%s", name);
    initializeBlocks();
    initializeWalls();
    map[i = 18][j = 9] = 5;
    map[19][startBoard] = map[19][startBoard + 1] = map[19][startBoard + 2] = 3;
    if (transferBall(1, &i, &j) == -1)
    {
        clearScreen();
        printMap();
        printf("\n");
        printlost();
        printf("press any key to continue");
    }
    FILE *scoreData = fopen("scoreData.txt", "at");
    score = calculateScore();
    fprintf(scoreData, "%s:%d\n", name, score);
    fclose(scoreData);
    while (!_kbhit())
        ;
}
void scoreBoard()
{
    clearScreen();
    FILE *scoreData = fopen("scoreData.txt", "rt");
    while (!feof(scoreData))
    {
        char name[40];
        fscanf(scoreData, "%s", name);
        printf("%s\n", name);
    }
    printf(" \33[47m\033[1;30mExit\033[0m\n");
    fclose(scoreData);
    while (!_kbhit())
        ;
}
int menu()
{
    int i = printMenu();
    switch (i)
    {
    case 0:
        startGame();
        menu();
        break;
    case 1:
        scoreBoard();
        menu();
        break;
    case 2:

        break;
    case 3:
        return 0;
        break;
    }
}
int main()
{
    menu();
}
