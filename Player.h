#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();
        //need more actions in here:
        //after inserting the head and before removing the tail 
        // -- check if the new head position collides with the food 
        // -- if yes increment the socre in gm mechanics, generate new food, 
        //and do not remove tail 
        // -- if not remove tail and move on

        //lastly add self collision check 
        // -- if self collied you will set lose flag and exit the program through gm 
        // -- this will break the program loop and end the game 


        // -- ending you need to differentiat ethe end gamme type 
    

    private:
        objPosArrayList *playerPosList;   // Upgrade this in iteration 3.       
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif