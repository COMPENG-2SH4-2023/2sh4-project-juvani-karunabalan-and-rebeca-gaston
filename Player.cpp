#include "Player.h"
#include <iostream>


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPos.setObjPos(5,5,'*'); //sets inital position

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
    //Get's keyboard input
    char input = mainGameMechsRef->getInput();
    // PPA3 input processing logic
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
            
}

void Player::movePlayer()
{
    //collects the boundary values of the game board
    int xbound = (mainGameMechsRef->getBoardSizeX()-2);
    int ybound = (mainGameMechsRef->getBoardSizeY()-2);
    // PPA3 Finite State Machine logic
    switch (myDir)
    {
        case UP:
            playerPos.y -= 1;
            if (playerPos.y < 1)
            {
                playerPos.y = ybound;
            }
            break;

        case DOWN:
            playerPos.y += 1;
            if (playerPos.y > ybound)
            {
                playerPos.y = 1;
            }
            break;

        case RIGHT:
            playerPos.x += 1;
            if (playerPos.x > xbound)
            {
                playerPos.x = 1;
            }
            break;
        
        case LEFT:
            playerPos.x -= 1;
            if (playerPos.x < 1)
            {
                playerPos.x = xbound;
            }
            break;  

        default:
            break;
    }
}

