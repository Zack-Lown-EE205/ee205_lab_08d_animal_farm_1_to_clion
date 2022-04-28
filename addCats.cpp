///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   27_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "addCats.h"
#include <cstring>
//Declares bool type
#include "catDatabase.h"
bool addCat(Cat* newCat){
    newCat->next = catDatabaseHeadPointer; //This sets the new Cat's "next" value to the HeadPointer.If its the first cat this will be the nullpointer but after itll point to the next cat.
    catDatabaseHeadPointer = newCat;// Set the CatdbHeadPointer to the new first cat in the linked list.
    currentCatNum ++; //Keeps track of number of cats in the database
    return true;
}
