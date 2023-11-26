#include "Food.h"
#include <time.h>
#include <stdio.h>
#include "MacUILib.h"


//think about where to seed the RNG
//look at PPA 3

//CAREFUL WITH FOODGM POINTER




Food::Food(GameMechs* foodGM)
{
    srand(time(NULL));
    foodPos.setObjPos(-2,-2, 'O');
    
    mainGMrefFood = foodGM;
    
}

Food::~Food()
{
    //delete foodGM;
}

void Food::generateFood(objPos blockOff)
{

    //generate random x and y coord, make sure they are NOT border or blockOff pos
    int xcandidate, ycandidate;
    
    //check x and y against 0 and boardSizeX/Y
    
    xcandidate = (rand()% (mainGMrefFood->getBoardSizeX()-2)) + 1; //mainGMrefFood->getBoardSizeX() LEAVES SEG FAULT???

                                                            //rand num % 18 giving [0,17], however 0 is the border so +1 to the candidate for coords
                                                            // THEREFORE item x range is [1,...,18] and the borders are 0 and 19

    ycandidate = (rand()% (mainGMrefFood->getBoardSizeY()-2)) + 1;    //mainGMrefFood->getBoardSizeY() LEAVES SEG FAULT???
                                                            //rand num %8 giving [0,7], add 1 to get all y.coords in between border
                                                            // THEREFORE item y range is [1,...,8] and the borders are 0 and 9
 
    foodPos.setObjPos(xcandidate, ycandidate, 'O');

    //remember, in objPos use isPosEqual() 
    
    if(blockOff.isPosEqual(&foodPos)){
        xcandidate = (rand()% (mainGMrefFood->getBoardSizeX()-2)) + 1;    //foodGM->getBoardSizeX()-2
        ycandidate = (rand()% (mainGMrefFood->getBoardSizeY()-2)) + 1;    //foodGM->getBoardSizeY()

        foodPos.setObjPos(xcandidate, ycandidate, 'O');

    }
    
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}