#include "GameMechs.h"
#include <MacUILib.h>

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    boardSizeX = 20;    //1b on doc recommmended 30 and 15 but vid did this
    boardSizeY = 10;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    boardSizeX = boardX; 
    boardSizeY = boardY;
}

// do you need a destructor?
//not yet, havent accessed heap yet



bool GameMechs::getExitFlagStatus()
{
     return exitFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar() !=0)
    {
        input = MacUILib_getChar();  // last typed value stored

    }
    return input;
}
//added
bool GameMechs::getLoseFlagStatus()
{

}
int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

// added since it was in UML
int GameMechs::getScore()
{
    return score;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

//added
void GameMechs::setLoseFlag()
{

}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{
    score++;
}


