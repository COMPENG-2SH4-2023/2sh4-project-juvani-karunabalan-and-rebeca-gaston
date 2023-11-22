#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        bool loseFlag; //left out, was in UML
        int score;  //left out, was in UML
        
        int boardSizeX;
        int boardSizeY;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        //~GameMechs();

        bool getExitFlagStatus();
        bool getLoseFlagStatus(); //implemented

        char getInput();
        int getBoardSizeX();
        int getBoardSizeY();
        int getScore();

        void setExitTrue();
        void setLoseFlag(); //added

        void setInput(char this_input);
        void clearInput();

        void incrementScore();
      

};

#endif