///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   27_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "reportCats.h"
#include "catDatabase.h"

//----------------------------------------Enum Converters---------------------------------------------------------------
extern const char* toColor ( const Color color ) { //BLACK,WHITE,PURPLE,BLUE,AQUA,GREEN,YELLOW,ORANGE,RED,PINK,BROWN,RAINBOW,OTHER
    switch(color){
        case 0:	return "Black";
        case 1:	return "White";
        case 2:	return "Purple";
        case 3:	return "Blue";
        case 4:	return "Aqua";
        case 5:	return "Green";
        case 6:	return "Yellow";
        case 7:	return "Orange";
        case 8: return "Red";
        case 9: return "Pink";
        case 10:return "brown";
        case 11:return "Rainbow";
        case 12:return "Other";
        default:return "How'd you even do this??";
    }//End of switch
}//End of toColor

extern const char* toBreedName ( const Breed breed){ //UNKNOWN_BREED,MAINE_COON,MANX,SHORTHAIR,PERSIAN,SPHYNX
    switch(breed){
        case 0: return "Unknown Breed";
        case 1: return "Maine Coon";
        case 2: return "Manx";
        case 3: return "Shorthair";
        case 4: return "Persian";
        case 5: return "Sphynx";
        default: return "How'd you even do this??";
    }//End of switch
}//End of toBreedName

const char* toGenderName ( const Gender gender){ //UNKNOWN_GENDER,MALE,FEMALE
    switch(gender){
        case 0: return "Unknown";
        case 1: return "Male";
        case 2: return "Female";
        default: return "How'd you even do this??";
    }//End of Switch
}//End of toGenderName

const char* toIsFixedName (const bool isFixed){
    if(isFixed){
        return "true";
    } else {
        return "false";
    }
}//End of toIsFixedName

bool printAllCats() {
    int numCats = 0 ;
    for(Cat* iCat = catDatabaseHeadPointer ; iCat != nullptr ; iCat = iCat->next ) {
        iCat->print();
        numCats++;
    }//End of for
    return true;
}//End of printAllCats

Cat* findCatByName(const char* nameToFind) {
     //This sets the index to the first cat; this'll be traversed in the for loop
    for (Cat* traversingCat = catDatabaseHeadPointer; traversingCat != nullptr ; traversingCat = traversingCat->next) {
        if (strcmp(nameToFind,traversingCat->getName()) == 0) {//If name we're trying to find is the name of the traversing cat,
            return traversingCat;//Return the cat
        }//End of if
    }//End of for
    return nullptr; //Returned if no cat in the database has that name
}//End of findCatByName
