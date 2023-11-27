#include "Player.h"
#include <iostream>


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'*'); //sets inital position
    
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
    
    //debugging purpose insert head 4 more imes
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
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
    objPos currHead; //holds positon of current head
    playerPosList->getHeadElement(currHead);

    //collects the boundary values of the game board
    int xbound = (mainGameMechsRef->getBoardSizeX()-2);
    int ybound = (mainGameMechsRef->getBoardSizeY()-2);
    // PPA3 Finite State Machine logic
    switch (myDir)
    {
        case UP:
            currHead.y -= 1;
            if (currHead.y < 1)
            {
                currHead.y = ybound;
            }
            break;

        case DOWN:
            currHead.y += 1;
            if (currHead.y > ybound)
            {
                currHead.y = 1;
            }
            break;

        case RIGHT:
            currHead.x += 1;
            if (currHead.x > xbound)
            {
                currHead.x = 1;
            }
            break;
        
        case LEFT:
            currHead.x -= 1;
            if (currHead.x < 1)
            {
                currHead.x = xbound;
            }
            break;  
        
        case STOP:
        default:
            break;
    }

    playerPosList->insertHead(currHead);  //adds the current head
    playerPosList->removeTail();         //removes the tail

}

