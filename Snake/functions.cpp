#include <iostream>
#include <conio.h>
#include <windows.h>

#include "functions.h"

using namespace std;

bool gameOver = false;

const int mapWidth = 20;
const int mapHeight = 20;

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100]; 
int tailLen;

eDirection direction;

void setUp()
{
    gameOver = false;

    direction = STOP;

    x = mapWidth / 2;
    y = mapHeight / 2;

    fruitX = rand() % mapWidth;
    fruitY = rand() % mapHeight;
}

void draw()
{
    system("cls");

    for (int i = 0; i < mapWidth; ++i)
    {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < mapHeight; ++i)
    {
        for (int j = 0; j < mapWidth; ++j)
        {
            if (j == 0)
            {
                cout << "#";
            }

            if (i == y && j == x)
            {
                cout << "O";
            }
            else if (i == fruitY && j == fruitX)
            {
                cout << "F";
            }
            else
            {
                bool print = false;
                for (int k = 0; k < tailLen; ++k)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }

                if (!print)
                {
                cout << " ";
                }
            }

            if (j == mapWidth - 1)
            {
                cout << "#";
            }
        }

        cout << endl;
    }

    for (int i = 0; i < mapWidth + 2; ++i)
    {
        cout << "#";
    }
    cout << "\nScore: " << score;
}

void input()
{
    if (_kbhit())
    {
       switch (_getch())
       {
        case 'w' : direction = UP; break;
        case 'a' : direction = LEFT; break;
        case 's' : direction = DOWN; break;
        case 'd' : direction = RIGHT; break;
        case 'x' : gameOver = true; break;
       }
    }
}

void logic()
{

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < tailLen; ++i)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];

        tailX[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (direction)
    {
        case UP : --y; break;
        case LEFT : --x; break;
        case DOWN : ++y; break;
        case RIGHT : ++x; break;
    }

    if (x > mapWidth || x < 0 || y > mapHeight || y < 0)
    {
        gameOver = true;
    }

    for (int i = 0; i < tailLen; ++i)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
        }
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;

        fruitX = rand() % mapWidth;
        fruitY = rand() % mapHeight;

        ++tailLen;
    }

}