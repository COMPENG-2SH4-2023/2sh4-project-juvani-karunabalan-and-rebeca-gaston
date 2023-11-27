#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; //creates 200 elements 
    sizeArray = ARRAY_MAX_CAP;
    sizeList = 0; //no elements in list at the start 
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (sizeList < sizeArray)
    {
        //shifts alll elements towards the tail to open a spot at the head
        for (int i = sizeList; i > 0; i--)
        {
            aList[i].setObjPos(aList[i-1]);
        }
        //fills the head spot with the new element
        aList[0].setObjPos(thisPos);
        //incremnt the size of list
        sizeList++;
    }

}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (sizeList < sizeArray)
    {
        //fills the tail spot with the new element
        aList[sizeList].setObjPos(thisPos);
        //incremnt the size of list
        sizeList++;
    }
}

void objPosArrayList::removeHead()
{
    
    //shifts alll elements towards the head to remove a spot at the head
    for (int i = 0; i < sizeList; i++)
    {
        aList[i].setObjPos(aList[i+1]);  
        //how to delete the last spot data?
    }
    //delete the last element/ set to null 
    aList[sizeList-1].setObjPos(0,0,0);
    //decremnt the size of list
    sizeList--;
    
}

void objPosArrayList::removeTail()
{
    //how to delet data? 
    aList[sizeList-1].setObjPos(0,0,0);
    //decremnt the size of list
    sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}