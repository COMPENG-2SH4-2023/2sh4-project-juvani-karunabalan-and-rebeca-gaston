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

    while(myGM->getExitFlagStatus()  == false && myGM->getLoseFlagStatus() == false)  
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
    board.setObjPos(0,0,'#');

    myGM = new GameMechs(20,10);
    myPlayer = new Player(myGM);

    //pass the address myGM into the player so the player can see the same
    //game mechanism class instance (board size 26 and 13) on the heap

    

}

void GetInput(void)
{
   myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    if (myGM->getInput() == 27){    //setting exit key to escape
        myGM->setExitTrue();
    }   

    else if (myGM->getInput() == 'x'){  //setting lose key (debug)
        myGM->setLoseFlag();
    }

    else if (myGM->getInput() == 'q'){   // setting score key (debug)
        myGM->incrementScore();
    } 


    myGM->clearInput();


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
            else if (j == tempPos.x && i == tempPos.y)
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

    MacUILib_printf("BoardSize: %dx%d, Player Pos: <%d, %d> + %c\n", 
                                                myGM->getBoardSizeX(),
                                                myGM->getBoardSizeY(),
                                                tempPos.x, tempPos.y, tempPos.symbol);

    MacUILib_printf("Score: %d\n", myGM->getScore());
    
    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  

    if (myGM->getLoseFlagStatus()){
        MacUILib_printf("You lost womp womp :(");
    }

    else{
        MacUILib_printf("Game exited sucessfully.");
    }
    
    delete myGM;
    delete myPlayer;  
  
    MacUILib_uninit();
}
