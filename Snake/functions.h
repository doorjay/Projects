#ifndef FUNCTIONS_H
#define FUNCTIONS_H

const int mapWidth = 20;
const int mapHeight = 20;

/**
 * starts the game
 * snake head doesn't move, placed in center of map
 * randomly places a fruit within the bounds of the map
 */ 
void setUp();

/**
 * 
 */ 
void draw();

void logic(bool gameOver);

void input(bool gameOver);

enum eDirection 
{
    STOP = 0, LEFT, RIGHT, UP, DOWN
};

class Fruit
{
public:
    Fruit() : xCord(rand() % mapWidth), yCord(rand() % mapHeight) {}

    // getters
    int getX() { return xCord; }
    int getY() { return yCord; }

    // setters
    void setX(int x) { xCord = x; }
    void setY(int y) { yCord = y; }

    ~Fruit() {}

private:
    int xCord, yCord;
};

class Snake
{
public:
    Snake() 
        : xHead(mapWidth / 2), yHead(mapHeight / 2), tailLen(0) {}

    // getters
    int getXHead() { return xHead; }
    int getYHead() { return yHead; }
    int getTailLen() { return tailLen; }
    int getXTail(int index) { return xTail[index]; }
    int getYTail(int index) { return yTail[index]; }

    // setters
    void setXHead(int x) { xHead = x; }
    void setYHead(int y) { yHead = y; }
    void setTailLen(int len) { tailLen = len; }
    void setXTail(int value, int index) { xTail[index] = value; }
    void setYTail(int value, int index) { yTail[index] = value; }

private:
    int xHead, yHead, tailLen;
    int xTail[100], yTail[100]; 
};

#endif