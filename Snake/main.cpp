#include <iostream>
#include <conio.h>
#include <windows.h>

#include "functions.h"

using namespace std;

int main()
{
    setUp();

    while (!gameOver)
    {
        draw();
        input();
        logic();

        Sleep(50);
    }

    return 0;
}