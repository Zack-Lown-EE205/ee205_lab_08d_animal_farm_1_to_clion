///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   27_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "deleteCats.h"
#include "catDatabase.h"

int deleteCat(const Cat* index) {
    if(index == catDatabaseHeadPointer){//If index is for the first cat.
        catDatabaseHeadPointer = catDatabaseHeadPointer->next;// Because this was the first cat, set the catDatabaseHeadPointer to the next cat in the DB.
        delete index; // Delete the cat
        currentCatNum = currentCatNum-1;
        return 0;
    }
    //Done in the case of the cat not being the first
    Cat* traversingCat = catDatabaseHeadPointer; //This sets the index to the first cat; this'll be traversed in the for loop
    for(int i = 0; currentCatNum; i++){
        if(traversingCat->next == index){//If the next value of traversing cat is equal to the one of the index,
            traversingCat->next = index->next;//Set the next value of the traversing cat to the next value of the cat being deleted as not to break the linked list
            delete index;//Delete the cat
            currentCatNum= currentCatNum -1;
            return 0;
        }//End of if
    }//End of for loop
    return 1;//Cat not in db
}//End of deleteCat

int deleteAllCats() {
    while(catDatabaseHeadPointer!= nullptr){
        deleteCat(catDatabaseHeadPointer);//Once the first Cat is deleted(the one with catDBheadpointer), the 2nd cat is assigned catDBheadpointer and then deleted and so on
    }//End of while
    return 0;
}//End of deleteAllCats

