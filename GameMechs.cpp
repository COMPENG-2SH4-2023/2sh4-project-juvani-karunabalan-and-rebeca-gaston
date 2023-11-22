#include "GameMechs.h"
#include <MacUILib.h>

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;   //added it 1b
    score = 0;          //added it 1b
    boardSizeX = 20;    //1b on doc recommmended 30 and 15 but vid did this
    boardSizeY = 10;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;   //added it 1b
    score = 0;          //added it 1b
    boardSizeX = boardX; 
    boardSizeY = boardY;
}

// do you need a destructor?
//not yet, havent accessed heap yet

GameMechs::~GameMechs(){

}


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
    return loseFlag;
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
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

void GameMechs::incrementScore(){
    score++;
}


