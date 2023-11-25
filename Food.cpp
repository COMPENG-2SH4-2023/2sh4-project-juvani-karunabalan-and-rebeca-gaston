#include "Food.h"
#include <MacUILib.h>


//think about where to seed the RNG
//look at PPA 3


Food::Food()
{
    foodPos.setObjPos(-1,-1,'o');
}

Food::~Food()
{

}

void generateFood(objPos blockOff)
{
    //generate random x and y coord, make sure they are NOT border or blockOff pos

    //check x and y against 0 and boardSizeX/Y

    //remember, in objPos use isPosEqual() 
}

void getFoodPos(objPos &returnPos)
{

}