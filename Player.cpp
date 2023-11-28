#include "Player.h"
#include "Food.h"
#include <iostream>


Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    mainFood = thisFoodRef;

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'*'); //sets inital position
    
    playerPosList = new objPosArrayList();
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

bool Player::checkFoodConsumption(objPos head)
{
    bool flag = false;
    objPos foodlocation; //holds position of food location
    mainFood->getFoodPos(foodlocation);

    if (foodlocation.x == head.x && foodlocation.y == head.y)
    {
        flag = true; 
    }
    return flag;

}


void Player::increasePlayerLength(objPos head)
{
    playerPosList->insertHead(head);   //inserts head 
}

bool Player::checkSelfCollision(objPos head)
{
    bool flag = false;
    objPos temp;      //holds temporary position of elemenst in playerPosList

    for (int i = 0; i < playerPosList->getSize() && mainGameMechsRef->getScore() != 0; i++)
    {
        playerPosList->getElement(temp, i);
        if (head.isPosEqual(&temp))
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
            flag = true;
        }
        
    }
    return flag;
}

void Player::movePlayer()
{
    objPos currHead; //holds positon of current head 
    playerPosList->getHeadElement(currHead);
    objPos foodlocation; //holds position of food location

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

    //mainFood->getFoodPos(foodlocation);
    
    if (checkSelfCollision(currHead) == false)
    {
        increasePlayerLength(currHead);     //inserts head only 
        if (checkFoodConsumption(currHead))         //IMPLEMENTED THE CHECKFOODCONSUMPTION FUNCTION
        { 
            mainFood->generateFood(playerPosList);
            mainGameMechsRef->incrementScore();
        }
        else
        {
            playerPosList->removeTail();         //removes the tail
        }
    }

    

}


