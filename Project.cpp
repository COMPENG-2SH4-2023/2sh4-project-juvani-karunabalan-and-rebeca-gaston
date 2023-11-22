#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;
Player* myPlayer;
GameMechs* myGM;
objPos board;
objPos space;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen(); 
    myGM = new GameMechs(20,10);
    myPlayer = new Player(myGM);
    board.setObjPos(0,0,'#');

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    objPos tempPos; //create an instance for temporary pos
    myPlayer->getPlayerPos(tempPos); //get the player pos
    int i,j;

    //drawing the border #####, how to implement with board position functions in objPos class?
    for(i=0; i<myGM->getBoardSizeY(); i++)
    {

        for(j=0; j<myGM->getBoardSizeX(); j++)
        {

            if(i==0 || i== myGM->getBoardSizeY()-1 || j==0 || j== myGM->getBoardSizeX()-1)
            {
                MacUILib_printf("%c", board.getSymbol());
            }
            else if (i == tempPos.x && j == tempPos.y)
            {
                MacUILib_printf("%c", tempPos.getSymbol());
            }
            else
            {
                MacUILib_printf("%c",' ');
            }

        }
        
        printf("\n");

    }
    
    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
