#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"

class Food
{
    private:
        objPos foodPos;
        GameMechs* mainGMrefFood;
        //objPosArrayList* PosList;

    public:
        Food(GameMechs* foodGM);
        ~Food();

        void generateFood(objPosArrayList* objList);   //You need to upgrade this somehow...
        //you need to accept player body array list element to amke sure they are all
        //lined up with random food generation 
        void getFoodPos(objPos &returnPos);
};

#endif