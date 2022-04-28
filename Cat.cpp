///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   27_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cstring>
#include "Cat.h"
#include "reportCats.h"
#include <stdexcept>//Used in validators for throwing exceptions
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace std;

//----------------------------------------Constructors---------------------------------------------------------------
Cat::Cat() {
    clearCatData();
}

Cat::Cat(const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight) {
    setName( newName);
    setGender( newGender);
    setBreed( newBreed);
    setWeight( newWeight);
    //Default isFixed = false
    //All other fields should be zero'd out
    //assert(validate());
}//End of 2nd Cat Constructor

//---------------------------------------------------Setters----------------------------------------------------------
//This takes over updateCats.c/h
void Cat::setName(const char *newName) {
    validateName(newName);
    strcpy(name, newName);
}

void Cat::setGender(const Gender newGender) {
    //if( gender != UNKNOWN_GENDER ) {
    //    throw logic_error( PROGRAM_NAME ": You can't change the cat's gender") ;
    //}
    validateGender(newGender) ; //Make sure New Gender isn't UNKNOWN
    Cat::gender = newGender;

}

void Cat::setBreed(const Breed newBreed) {
    //if( breed != UNKNOWN_BREED ) {
    //    throw logic_error( PROGRAM_NAME ": The breed is already set, you can't change it" ) ;
   //}
    validateBreed(newBreed);
    Cat::breed = newBreed;

}

void Cat::setWeight(const Weight newWeight ) {
    validateWeight(newWeight);
    Cat::weight = newWeight;
}

void Cat::fixCat() noexcept {
    Cat::isFixed = true;
}


//------------------------ noexcept--------------------Getters---------------------------------------------------------
const char* Cat::getName() const noexcept {
    return name;
}

Gender Cat::getGender() const noexcept {
    return gender;
}

Breed Cat::getBreed() const noexcept {
    return breed;
}

Weight Cat::getWeight() const noexcept {
    return weight;
}

bool Cat:: getIsFixed() const noexcept {
    return isFixed;
}

//-------------------------------------------Validators----------------------------------------------------------------
bool Cat::validate() const noexcept {
    try {
        validateName( name ) ;
        validateBreed( breed ) ;
        validateGender( gender ) ;
        validateWeight( weight ) ;
    } catch (exception const& e) {//MARKS CODE---CHANGE
        cout << e.what() << endl ;//MARKS CODE--CHANGE
        return false ;
    }//End of Try-Catch
    return true;
}//End of Validate

bool Cat::validateName(const char *newName){
    if(newName == nullptr ){ // If name parameter is empty...
        throw invalid_argument(PROGRAM_NAME ": name cannot be empty.");
    }//End of if
    if( strlen(newName) >= MAX_NAME_LENGTH){ //If name parameter is too long...
        throw length_error(PROGRAM_NAME ": The cat's name is too long; must be under 50 characters.");//50 as defined by MAX_NAME_LENGTH
    }//End of if
    if( strlen( newName ) <= 0 ) {//If name parameter is empty (different than nullptr)
        throw length_error( PROGRAM_NAME ": name length must be > 0");
    }//End of if
    return true;//Returns true if all tests pass, otherwise nothing is returned (false)
}//End of validateName

bool Cat::validateGender(const Gender newGender){
    if( newGender == UNKNOWN_GENDER){
        throw invalid_argument(PROGRAM_NAME ": The cat's gender can't be unknown.");
    }
    return true;
}

bool Cat::validateBreed(const Breed newBreed){
    if( newBreed == UNKNOWN_BREED){
        throw invalid_argument(PROGRAM_NAME ": The cat's breed can't be unknown.");
    }
    return true;
}

bool Cat::validateWeight(const Weight newWeight){
    if( newWeight <= 0 || newWeight > MAX_CAT_WEIGHT ){ //If weight less than or equal to zero or unreasonable
        throw invalid_argument(PROGRAM_NAME ": The cat's weight must be greater than zero and reasonable.");
    }
    return true;
}

//bool validateIfFixPossible() {
    //if(Cat::isFixed == true){
    //    throw logic_error(PROGRAM_NAME ": The cat has already been fixed, this isn't possible ");
    //}
//    return true;//I'd like to check to see if cat has already been fixed but dont know how. Will ask prof
//}

//--------------------------------------------------Misc---------------------------------------------------------------
void Cat::clearCatData() {
    memset( name, 0, MAX_NAME_LENGTH);
    gender = UNKNOWN_GENDER;
    breed = UNKNOWN_BREED;
    isFixed = false;
    weight = -1;
    next = nullptr;
}

/// Format a line for printing the members of a class
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)
/// @returns true if everything worked correctly. false if something goeswrong
bool Cat::print() const noexcept {
    assert( validate() ) ;
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" ) << getName() << endl ;
    FORMAT_LINE( "Cat", "gender" ) << toGenderName( getGender() ) << endl ;
    FORMAT_LINE( "Cat", "breed" ) << toBreedName( getBreed() ) << endl ;
    FORMAT_LINE( "Cat", "isFixed" ) << toIsFixedName(getIsFixed()) << endl ;
    FORMAT_LINE( "Cat", "weight" ) << getWeight() << endl ;
    return true ;
}


/*
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
 */

