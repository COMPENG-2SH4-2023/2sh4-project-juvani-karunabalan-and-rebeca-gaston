#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include "objPosArrayList.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;
Player* myPlayer;
GameMechs* myGM;

Food* myFood;
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
    myFood = new Food(myGM);

    //pass the address myGM into the player so the player can see the same
    //game mechanism class instance (board size 26 and 13) on the heap


    //think about when to generate the new food

    objPos playerPosCheck(-1,-1,'o'); //create an instance for temporary pos
   //myPlayer->getPlayerPos(playerPosCheck); //get the player pos
    myFood->generateFood(playerPosCheck); //turn into array list argument 
    
    //think about whther you wamt to set up a debug key
    //to call the food generation routine for verification
    
    //remember, generateFood() requires player reference.
    //You will need to provide it AFTER player object is instantiated
    

}

void GetInput(void)
{
   myGM->getInput();
}

void RunLogic(void)
{

    objPos playerPosCheck; //create an instance for temporary pos
    myPlayer->getPlayerPos(); //get the player pos //removed playerPosCheck from the brackets 

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

    else if (myGM->getInput() == 'f'){   // setting generate food key (debug)

        myFood->generateFood(playerPosCheck);
    } 


    myGM->clearInput();


}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 

    bool drawn;

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    objPos tempFood;
    myFood->getFoodPos(tempFood);

    int i,j;

    //drawing the border #####, how to implement with board position functions in objPos class?
    for(i=0; i<myGM->getBoardSizeY(); i++)
    {
        
        for(j=0; j<myGM->getBoardSizeX(); j++)
        {
            drawn = false;
            //iterate thourgh every single element on the list
            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody,k);
                if(tempBody.x == j && tempBody.y == i && drawn == false)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                }
            }

            if (drawn) continue;
            //if player body was drawn, don't draw anything below

            if(i==0 || i== myGM->getBoardSizeY()-1 || j==0 || j== myGM->getBoardSizeX()-1)
            {
                MacUILib_printf("%c", board.getSymbol());
            }

            else if (j == tempFood.x && i == tempFood.y)
            {
                MacUILib_printf("%c", tempFood.symbol);

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
                                                tempBody.x, tempBody.y, tempBody.symbol);

    MacUILib_printf("Score: %d\n", myGM->getScore());
    //MacUILib_printf("Food Coords: %d\n", );

    MacUILib_printf("Player Positions: \n");
    for (int l = 0; l < playerBody->getSize(); l++)
    {
        playerBody->getElement(tempBody, l);
        MacUILib_printf("<%d, %d>", tempBody.x, tempBody.y);
    }
    
    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  

    if (myGM->getLoseFlagStatus()){
        MacUILib_printf("You lost womp womp (T-T)\n");
    }

    else{
        MacUILib_printf("Game exited sucessfully.");
    }
    
    delete myGM;
    delete myPlayer;  
    delete myFood;
  
    MacUILib_uninit();
}
