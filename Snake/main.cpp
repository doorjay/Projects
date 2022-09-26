#include <iostream>
#include <conio.h>
#include <windows.h>

#include "functions.h"

using namespace std;

int main()
{
    setUp();

    bool gameOver = false;

    while (!gameOver)
    {
        draw();
        input(gameOver);
        logic(gameOver);

        Sleep(50);
    }

    return 0;
}