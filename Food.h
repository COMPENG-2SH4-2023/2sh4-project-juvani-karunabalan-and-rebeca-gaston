#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"

class Food
{
    private:
        objPos foodPos;
        GameMechs* mainGMrefFood;

    public:
        Food(GameMechs* foodGM);
        ~Food();

        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);
};

#endif