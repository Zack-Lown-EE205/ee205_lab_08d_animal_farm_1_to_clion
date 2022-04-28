///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   18_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <cstddef>  // Allows for size_t. Could also use stdio.h if needed later
#include <ctime>
#include "Cat.h"

//----------------------------------------------------------------------------------------------------------------------
typedef size_t CurrentCatNum;

extern Cat* catDatabaseHeadPointer ;
extern CurrentCatNum currentCatNum;

//---------------------------------------------------------------------------------------------------------------------
/*
//Defines the enum's
typedef enum {UNKNOWN_GENDER,MALE,FEMALE} Gender;
typedef enum {UNKNOWN_BREED,MAINE_COON,MANX,SHORTHAIR,PERSIAN,SPHYNX} Breed;
typedef enum {BLACK,WHITE,PURPLE,BLUE,AQUA,GREEN,YELLOW,ORANGE,RED,PINK,BROWN,RAINBOW,OTHER} Color;


//Defines aliases
typedef size_t NumCats; // Sets a new datatype , NumCats, as alias to size_t
typedef float Weight;
typedef unsigned long long License;
typedef struct tm Birthday;

//This creates a new datatype (cats) with the applicable fields.
struct Cat {
    //Data type           Data name
    char                name[MAX_NAME_LENGTH];
    Gender              gender;         //enum genders declared above
    Breed               breed;          //enum breeds declared above
    bool                isFixed;
    Weight              weight;
    Color               collarColor1;   //enum color declared above
    Color               collarColor2;   //...
    unsigned long long  license;
    Birthday            birthday;       //Used for storing birthday
};


extern int initializeDatabase();
extern struct Cat catdb[MAX_CATS]; //This doesn't allocate any memory, just says this fn is declared in catDatabase.c

//Function Declarations
extern bool isdbFull();
extern bool isNameValid(const char name[]);
extern bool isWeightValid(Weight weight);
extern bool isLicenseValid(License license);
extern bool isCollarValid(Color collarColor1, Color collarColor2);
extern bool isFixingCatPossible(NumCats index);
extern Birthday makeBirthday(const char birthday[]);
extern bool isBirthdayValid(Birthday birthday);
 */