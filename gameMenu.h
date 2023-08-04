#ifndef gameMenu
#define gameMenu

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "test2.h"
int scrollMenu(int *i, int min, int max)
{
    int x;
    if (_kbhit())
    {
        x = _getch();
        if (x == 224)
        {
            x = _getch();
        }
        switch (x)
        {
        case 77: // right

            break;
        case 75: // left

            break;
        case 72: // up
            if (*i > min)
                *i = *i - 1;
            break;
        case 80: // down
            if (*i < max)
            {
                *i = *i + 1;
            }
            break;
        case 13:
            return *i;
        }
    }
    return -1;
}
void printMenu1()
{
    printf(" \33[47m\033[1;30mStart Game\033[0m\n");
    printf("Score Board\n");
    printf("Setting\n");
    printf("Exit\n");
}
void printMenu2()
{
    printf("Start Game\n");
    printf(" \33[47m\033[1;30mScore Board\033[0m\n");
    printf("Setting\n");
    printf("Exit\n");
}
void printMenu3()
{
    printf("Start Game\n");
    printf("Score Board\n");
    printf(" \33[47m\033[1;30mSetting\033[0m\n");
    printf("Exit\n");
}
void printMenu4()
{
    printf("Start Game\n");
    printf("Score Board\n");
    printf("Setting\n");
    printf(" \33[47m\033[1;30mExit\033[0m\n");
}
int printMenu()
{
    int i = 0, min = 0, max = 3;
    while (scrollMenu(&i, min, max) == -1)
    {
        clearScreen();
        switch (i)
        {
        case 0:
            printMenu1();
            break;
        case 1:
            printMenu2();
            break;
        case 2:
            printMenu3();
            break;
        case 3:
            printMenu4();
            break;
        }
        sleep(500);
    }
    return i;
}
#endif