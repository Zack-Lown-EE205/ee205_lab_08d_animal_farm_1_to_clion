///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   18_Mar_2022
///////////////////////////////////////////////////////////////////////////////


#include <cstdio> //For printing
#include <cstring> //For strcpy
#include "catDatabase.h"
#include "config.h"
#include "updateCats.h"


/*---------------------------------------------------------------------------------------------------------------------
extern NumCats currentCatNum; // Declared externally in catDatabase.c

int updateCatName(const int index, const char newName[]){
    if(isNameValid(newName)){
        strcpy(catdb[index].name, newName);
        return 0;
    }
    return -1;
}//End of upDateCatName

int fixCat(const NumCats index){
    if(!isFixingCatPossible(index)){
        fprintf(stderr,"%s: %s has already been fixed... Thats not good... ", PROGRAM_NAME, catdb[index].name);
        return -1;
    }
    catdb[index].isFixed = true;
    return 0;
}//End of fixCat

int updateCatWeight(const NumCats index, const Weight newWeight){
    if(isWeightValid(newWeight)){
        catdb[index].weight = newWeight;
        return 0;
    }
    return -1;
}//End of updateCatWeight

int updateCatCollar1(const NumCats index, const Color newCatCollar1){
    if(isCollarValid(newCatCollar1, catdb[index].collarColor2)){
        catdb[index].collarColor1 = newCatCollar1;
        return 0;
    }
    return -1;
}//End of updateCatCollar1

int updateCatCollar2(const NumCats index, const Color newCatCollar2){
    if(isCollarValid(catdb[index].collarColor1, newCatCollar2)){
        catdb[index].collarColor2 = newCatCollar2;
        return 0;
    }
    return -1;
}//End of updateCatCollar2

int updateLicense(const NumCats index, const License newLicense){
    if (isLicenseValid(newLicense)){
        catdb[index].license = newLicense;
        return 0;
    }
    return -1;
}//End of updateLicense

int updateBirthday(const NumCats index, const char birthdayString[]){
    Birthday birthday = makeBirthday(birthdayString);//Convert birthday string to struct tm
    if(isBirthdayValid(birthday)){
        catdb[index].birthday = birthday;
        return 0;
    }
    return -1;
}
---------------------------------------------------------------------------------------------------------------------*/