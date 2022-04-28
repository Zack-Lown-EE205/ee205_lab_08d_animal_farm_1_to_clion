///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include "config.h"

typedef enum {UNKNOWN_GENDER,MALE,FEMALE} Gender;
typedef enum {UNKNOWN_BREED,MAINE_COON,MANX,SHORTHAIR,PERSIAN,SPHYNX} Breed;
typedef enum {BLACK,WHITE,PURPLE,BLUE,AQUA,GREEN,YELLOW,ORANGE,RED,PINK,BROWN,RAINBOW,OTHER} Color;
typedef float Weight;

class Cat {
//----------------------------Members--------------------------------------------
public:  //Public Member(s)
    Cat*        next ;                //The Pointer to the next object in the list
protected://Protected Members. Use Getters and Setters to get & set
    char        name[MAX_NAME_LENGTH] ;
    Gender      gender ;              //Cat Gender tydefed to enum
    Breed       breed ;               //Cat Breed typedefed to enum
    bool        isFixed ;
    Weight      weight ;              //Cat Weight typedefed to float
//--------------------------Constructors-----------------------------------------
public:
    Cat();
    Cat( const char *newName, Gender newGender, Breed newBreed, Weight newWeight );//If something goes wrong, add const back

//--------------------------Methods------------------------------------------------
public://Public Methods
    //--------------Getters-------------------
    const char *getName() const noexcept ;
    Gender getGender() const noexcept ;
    Breed getBreed() const noexcept ;
    Weight getWeight() const noexcept ;
    bool getIsFixed() const noexcept ;
    bool print() const noexcept ;
    //-------------Setters--------------------
    void setName( const char* newName );
    void setGender(Gender newGender);
    void setBreed(Breed newBreed);
    void setWeight(Weight newWeight) ;
    void fixCat() noexcept ;
    //------------Validators-----------------
    bool validate() const noexcept;
    // Static methods must be `const` -- From Mark's Code. Couldn't get this to not show warnings
    static bool validateName( const char* newName ) ;
    static bool validateGender( Gender newGender ) ;//If something goes wrong, add const back
    static bool validateBreed( Breed newBreed ) ;//If something goes wrong, add const back
    static bool validateWeight( Weight newWeight ) ;//If something goes wrong, add const back

private:
    void clearCatData();


};



