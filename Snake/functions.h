
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * starts the game
 */ 
void setUp();

void draw();

void logic();

void input();

enum eDirection 
{
    STOP = 0, LEFT, RIGHT, UP, DOWN
};

#endif