#include "Player.h"
#include <iostream>


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPos.setObjPos(5,5,'*');

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    //how to get input?
    char input = mainGameMechsRef->getInput();
    cout << "Input:" << input << endl;
    switch(input)
    {
        case 'w':  // UP keypress 
                if (myDir != DOWN)
                { 
                    myDir = UP;
                }
                break;
            
        case 's':  // DOWN keypress 
            if (myDir != UP)
            { 
                myDir = DOWN;
            }
            break;
        
        case 'd':  // RIGHT keypress 
            if (myDir != LEFT)
            { 
                myDir = RIGHT;
            }
            break;
        
        case 'a':  // LEFT keypress 
            if (myDir != RIGHT)
            { 
                myDir = LEFT;
            }
            break;

        default:
            break;

    }
    // PPA3 input processing logic        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    int xbound = (mainGameMechsRef->getBoardSizeX()-2);
    int ybound = (mainGameMechsRef->getBoardSizeY()-2);
    switch (myDir)
    {
        case UP:
            playerPos.x -= 1;
            if (playerPos.x < 1)
            {
                playerPos.x = ybound;
            }
            break;

        case DOWN:
            playerPos.x += 1;
            if (playerPos.x > ybound)
            {
                playerPos.x = 1;
            }
            break;

        case RIGHT:
            playerPos.y += 1;
            if (playerPos.y > xbound)
            {
                playerPos.y = 1;
            }
            break;
        
        case LEFT:
            playerPos.y -= 1;
            if (playerPos.y < 1)
            {
                playerPos.y = xbound;
            }
            break;  

        default:
            break;
    }
}

