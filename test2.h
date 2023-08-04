#ifndef test2
#define test2

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int map[20][20];
int startBoard = 8;
int boardDirection = 0;
void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}
int toNE(int *i, int *j)
{
    *i = *i - 1;
    *j = *j + 1;
}
int toNW(int *i, int *j)
{
    *i = *i - 1;
    *j = *j - 1;
}
int toSE(int *i, int *j)
{
    *i = *i + 1;
    *j = *j + 1;
}
int toSW(int *i, int *j)
{
    *i = *i + 1;
    *j = *j - 1;
}
int initializeBlocks()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 20; j++)
        {
            map[i][j] = 1;
        }
    }
}
int initializeWalls()
{
    int i;
    for (i = 0; i < 20; i++)
    {
        map[i][0] = map[i][19] = 2;
    }
}
int printMap()
{
    int i, j;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            switch (map[i][j])
            {
            case 1:
                printf("=");
                break;
            case 5:
                printf("*");
                break;
            case 0:
                printf(" ");
                break;
            case 3:
                printf("-");
                break;
            case 2:
                printf("|");
                break;
            }
        }
        printf("\n");
    }
}
void clearScreen()
{
    system("cls");
}
/*
directions:

2   |   1
    |
----------
    |
3   |   4
*/

int hitButton()
{
    int x;
    if (kbhit())
    {
        x = getch();
        if (x == 224)
        {
            x = getch();
        }
        switch (x)
        {
        case 77: // right
            boardDirection = 1;
            break;
        case 75: // left
            boardDirection = -1;
            break;
        case 72: // up
            boardDirection = 0;
            break;
        case 80: // down
            boardDirection = 0;
            break;
        case 113: // quit
            boardDirection = -10;
            break;
        }
    }
}
int transferBall(int direction, int *i, int *j)
{
    hitButton();
    if (boardDirection == -10)
    {
        return 0;
    }

    if (direction == 1)
    {
        hitButton();
        if (map[*i - 1][*j] == 1)
        {
            map[*i - 1][*j] = 0;
            return transferBall(4, i, j);
        }
        else if (map[*i - 1][*j + 1] == 1)
        {
            map[*i - 1][*j + 1] = 0;
            return transferBall(3, i, j);
        }
        else if (*i == 0)
        {
            return transferBall(4, i, j);
        }
        else if (*j == 18)
        {
            return transferBall(2, i, j);
        }
        else
        {
            hitButton();
            clearScreen();
            printMap();
            map[*i][*j] = 0;
            toNE(i, j);
            map[*i][*j] = 5;
            map[19][startBoard] = map[19][startBoard + 1] = map[19][startBoard + 2] = 0;
            hitButton();
            if (boardDirection == 1 && startBoard < 16)
            {
                startBoard++;
            }
            else if (boardDirection == -1 && startBoard > 1)
            {
                startBoard--;
            }
            map[19][startBoard] = map[19][startBoard + 1] = map[19][startBoard + 2] = 3;
            sleep(150);
            hitButton();
            return transferBall(1, i, j);
        }
    }
    hitButton();
    if (direction == 2)
    {
        hitButton();
        if (map[*i - 1][*j] == 1)
        {
            map[*i - 1][*j] = 0;
            return transferBall(3, i, j);
        }
        else if (map[*i - 1][*j - 1] == 1)
        {
            map[*i - 1][*j - 1] = 0;
            return transferBall(4, i, j);
        }
        else if (*i == 0)
        {
            return transferBall(3, i, j);
        }
        else if (*j == 1)
        {
            return transferBall(1, i, j);
        }
        else
        {
            hitButton();
            clearScreen();
            printMap();
            map[*i][*j] = 0;
            toNW(i, j);
            map[*i][*j] = 5;
            map[19][startBoard] = map[19][startBoard + 1] = map[19][startBoard + 2] = 0;
            hitButton();
            if (boardDirection == 1 && startBoard < 16)
            {
                startBoard++;
            }
            else if (boardDirection == -1 && startBoard > 1)
            {
                startBoard--;
            }
            map[19][startBoard] = map[19][startBoard + 1] = map[19][startBoard + 2] = 3;
            sleep(150);
            hitButton();
            return transferBall(2, i, j);
        }
    }
    hitButton();
    if (direction == 3)
    {
        hitButton();
        if (map[*i + 1][*j] == 1)
        {
            map[*i + 1][*j] = 0;
            return transferBall(2, i, j);
        }
        else if (*j == 1)
        {
            return transferBall(4, i, j);
        }
        else if (*i == 18)
        {
            if (map[*i + 1][*j] == 3)
            {
                return transferBall(2, i, j);
            }
            else if (map[*i +1][*j - 1] == 3)
            {
                return transferBall(1, i, j);
            }
            else
            {
                map[*i][*j] = 0;
                toSW(i, j);
                map[*i][*j] = 5;
                clearScreen();
                return -1;
            }
        }
        else
        {
            hitButton();
            clearScreen();
            printMap();
            map[*i][*j] = 0;
            toSW(i, j);
            map[*i][*j] = 5;
            map[19][startBoard] = map[19][startBoard + 1] = map[19][startBoard + 2] = 0;
            hitButton();
            if (boardDirection == 1 && startBoard < 16)
            {
                startBoard++;
            }
            else if (boardDirection == -1 && startBoard > 1)
            {
                startBoard--;
            }
            map[19][startBoard] = map[19][startBoard + 1] = map[19][startBoard + 2] = 3;
            sleep(150);
            hitButton();
            return transferBall(3, i, j);
        }
    }
    hitButton();
    if (direction == 4)
    {
        hitButton();
        if (map[*i + 1][*j] == 1)
        {
            map[*i + 1][*j] = 0;
            return transferBall(1, i, j);
        }
        else if (*j == 18)
        {
            return transferBall(3, i, j);
        }
        else if (*i == 18)
        {
            if (map[*i + 1][*j] == 3)
            {
                return transferBall(1, i, j);
            }
            else if (map[*i +1][*j + 1] == 3)
            {
                return transferBall(2, i, j);
            }
            else
            {
                map[*i][*j] = 0;
                toSE(i, j);
                map[*i][*j] = 5;
                clearScreen();
                return -1;
            }
        }
        else
        {
            hitButton();
            clearScreen();
            printMap();
            map[*i][*j] = 0;
            toSE(i, j);
            map[*i][*j] = 5;
            map[19][startBoard] = map[19][startBoard + 1] = map[19][startBoard + 2] = 0;
            hitButton();
            if (boardDirection == 1 && startBoard < 16)
            {
                startBoard++;
            }
            else if (boardDirection == -1 && startBoard > 1)
            {
                startBoard--;
            }
            map[19][startBoard] = map[19][startBoard + 1] = map[19][startBoard + 2] = 3;
            sleep(150);
            hitButton();
            return transferBall(4, i, j);
        }
    }
}
int printlost()
{
    printf(" __     __           _           _   \n");
    printf(" \\ \\   / /          | |         | |  \n");
    printf("  \\ \\_/ /__  _   _  | | ___  ___| |_ \n");
    printf("   \\   / _ \\| | | | | |/ _ \\/ __| __|\n");
    printf("    | | (_) | |_| | | | (_) \\__ \\ |_ \n");
    printf("    |_|\\___/ \\__,_| |_|\\___/|___/\\__|\n");
    printf("                                     \n");
}
int calculateScore()
{
    int i, j;
    int score = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (map[i][j] == 0)
            {
                score += ((3 - i) * 10);
            }
        }
    }
    return score;
}

#endif