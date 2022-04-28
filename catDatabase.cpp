///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Zack Lown <zacklown@hawaii.edu>
/// @date   18_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "catDatabase.h"
#include "Cat.h"
#include <cstring>     //Define strings
#include <cstdio>      //Define stderr
#include <cstdlib>     //Define atoi


//The pointer to nullptr that indicates the end of the linked list
Cat* catDatabaseHeadPointer = nullptr ;
CurrentCatNum currentCatNum= 0;


/*----------------------------------------------------------------------------------------------------------------------
//This creates the main array(catdb) that holds [MAX_CATS] number of cats. Values initialized to 0
struct Cat catdb[MAX_CATS]; //This does not declare a struct! Struct just says Cat is type struct. This does however make(allocate memory) the db of size [Max_CATS]

int initializeDatabase(){
    memset(catdb,0,sizeof(catdb));//Resets all data in catdb to 0
    currentCatNum = 0;
    return 0;
}//End of initializeDatabase

bool isdbFull(){
    if (currentCatNum >= MAX_CATS){
        fprintf(stderr, "%s: The cat database if already full! Cannot add any more cats.\n", PROGRAM_NAME);
        return true;
    } else {
        return false;
    }
}//End is isdbFull

bool isNameValid(const char name[]){
    bool value = true;
    if( strlen(name) <= 0 ){ // If name parameter is empty...
        fprintf(stderr, "%s: The cat's name cannot be blank.\n", PROGRAM_NAME);
        return false;
    }//End of if
    if( strlen(name) >= MAX_NAME_LENGTH){ ////If name parameter is too long...
        fprintf(stderr, "%s: The cat's name is too long; must be under 30 charachters.\n", PROGRAM_NAME);
        return false;
    }//End of if
    for(NumCats i= 0; i < currentCatNum; i++){ //Determine if name is unique
        if( strcmp(catdb[i].name,name) == 0 ){
            fprintf(stderr, "%s: The cat name %s is already taken, please choose another.\n", PROGRAM_NAME, name);
            value = false;
        }//End of if
    }//End of for loop
    return value;
}//End of isNameValid

bool isWeightValid(const Weight weight){
    if( weight <= 0 || weight > MAX_CAT_WEIGHT ){ //If weight less than or equal to zero or unreasonable
        fprintf(stderr, "%s: The cat's weight must be greater than zero and reasonable.\n", PROGRAM_NAME);
        return false;
    }//End of if
    return true;
}//End of isWeightValid

bool isLicenseValid(const License license){
    bool value = true;
    for(NumCats i= 0; i < currentCatNum; i++){ //Determine if License is unique
        if(catdb[i].license == license){
            value = false;
            fprintf(stderr, "%s: The License number is already in use on %s\n", PROGRAM_NAME, catdb[i].name);
        }//End of if
    }//End of for loop
    return value;
}//End of isLicenseValid

bool isCollarValid(const Color collarColor1, const Color collarColor2){
    bool value = true;
    if (collarColor1 == collarColor2){
        fprintf(stderr, "%s: The Cat collars cannot be the same color.\n", PROGRAM_NAME);
        value = false;
    }//End of if
    for(NumCats i = 0; i < currentCatNum; i++){ //Determine if catCollar combination is unique
        if((catdb[i].collarColor1 == collarColor1) && (catdb[i].collarColor2 == collarColor2)){
            fprintf(stderr, "%s: The Cat collar color combination is already in use on %s\n", PROGRAM_NAME, catdb[i].name);
            value = false;
        }//End of if
    }//End of for loop
    return value;
}//End of isCollarValid

bool isFixingCatPossible(const NumCats index){
    if(catdb[index].isFixed){
        return false;//False because cat has already been fixed
    }
    return true;
}//End of isFixingCatPossible

/// Convert a string to ...
/// @param birthdayString possible values include "XXXX", "XXXX", "XXXX"
Birthday makeBirthday(const char birthdayString[]){ //return a struct tm (tydef is called birthday)
    //This code splits the input string into 3 sections and stores it in an array
    char birthdayBuffer[20];//Used to store copy of birthday
    char *birthdayArray[5];//Array of pointers
    int i = 0;
    strcpy(birthdayBuffer, birthdayString);//strtok modifies a string directly; copy it to prevent overwriting
    birthdayArray[i] = strtok(birthdayBuffer," ");//get & set the first token(pointer) in the string to array.
    while( birthdayArray[i] != nullptr){ //Fill the array with elements until there are none left
        birthdayArray[++i] = strtok(nullptr," ");
    }//End of while
    birthdayArray[1][strlen(birthdayArray[1])-1] ='\0';//Removes comma from the day field.
    //This code sets the birth month to an int that can be interpreted by the tm function
    if(strcmp(birthdayArray[0],"Jan") == 0 || strcmp(birthdayArray[0],"January") == 0){
        birthdayArray[0] = (char*) "0";
    } else if(strcmp(birthdayArray[0],"Feb") == 0 || strcmp(birthdayArray[0],"Febuary") == 0){
        birthdayArray[0] = (char*)"1";
    } else if(strcmp(birthdayArray[0],"Mar") == 0 || strcmp(birthdayArray[0],"March") == 0){
        birthdayArray[0] = (char*)"2";
    } else if(strcmp(birthdayArray[0],"Apr") == 0 || strcmp(birthdayArray[0],"April") == 0){
        birthdayArray[0] = (char*)"3";
    } else if(strcmp(birthdayArray[0],"May") == 0 ){
        birthdayArray[0] = (char*)"4";
    } else if(strcmp(birthdayArray[0],"Jun") == 0 || strcmp(birthdayArray[0],"June") == 0){
        birthdayArray[0] = (char*)"5";
    } else if(strcmp(birthdayArray[0],"Jul") == 0 || strcmp(birthdayArray[0],"July") == 0){
        birthdayArray[0] = (char*)"6";
    } else if(strcmp(birthdayArray[0],"Aug") == 0 || strcmp(birthdayArray[0],"August") == 0){
        birthdayArray[0] = (char*)"7";
    } else if(strcmp(birthdayArray[0],"Sep") == 0 || strcmp(birthdayArray[0],"September") == 0){
        birthdayArray[0] = (char*)"8";
    } else if(strcmp(birthdayArray[0],"Oct") == 0 || strcmp(birthdayArray[0],"October") == 0){
        birthdayArray[0] = (char*)"9";
    } else if(strcmp(birthdayArray[0],"Nov") == 0 || strcmp(birthdayArray[0],"November") == 0){
        birthdayArray[0] = (char*)"10";
    } else if(strcmp(birthdayArray[0],"Dec") == 0 || strcmp(birthdayArray[0],"December") == 0){
        birthdayArray[0] = (char*)"11";
    } else{
        birthdayArray[0] = (char*)"-1";
    }
    //This code constructs the birthday array with the info we've collected/formatted
    Birthday birthday;
    birthday.tm_mon  = atoi(birthdayArray[0]);
    birthday.tm_mday = atoi(birthdayArray[1]);
    birthday.tm_year = atoi(birthdayArray[2])-1900;
    return birthday;
    //printf("Birthday: %s\n",asctime(&birthday));
}//End of makeBirthday

bool isBirthdayValid(Birthday birthday){
    char monthName[10];//Used to store Month name for error printing
    strftime(monthName,sizeof(monthName), "%B", &birthday);//Gets month name from struct tm number
    if(birthday.tm_mon <= -1 || birthday.tm_mon > 11){ //If month # is out of range
        fprintf(stderr, "%s: The cat's birth month is invalid.\n", PROGRAM_NAME);
        return false;
    }
    if(birthday.tm_mday > 31){ //If month has more than 31 days
        fprintf(stderr, "%s: The cat's birth day is invalid.\n", PROGRAM_NAME);
        return false;
    }
    if((birthday.tm_mon == 3 || birthday.tm_mon == 5 || birthday.tm_mon == 8 || birthday.tm_mon == 10) && birthday.tm_mday == 31 ){//If months with 30 days have more than 30
        fprintf(stderr, "%s: %s doesn't have 31 days.\n", PROGRAM_NAME, monthName);
        return false;
    }
    if(birthday.tm_mon == 1 && birthday.tm_mday > 28 && birthday.tm_year % 4 != 0){//If Febuary has > 28 days & not a leap year
        fprintf(stderr, "%s: February doesn't have %d days in %d.\n", PROGRAM_NAME, birthday.tm_mday, birthday.tm_year+1900);
        return false;
    }
    if(birthday.tm_mon == 1 && birthday.tm_mday > 29 && birthday.tm_year % 4 == 0){//If Febuary has > 29 days in a leap year
        fprintf(stderr, "%s: February doesn't have %d days.\n", PROGRAM_NAME, birthday.tm_mday);
        return false;
    }
    time_t currentTimeInSec = time(nullptr);//Sets currentTimeInSec to current time
    if(currentTimeInSec < mktime(&birthday)){ // If the current time since epoch is less than the cats birthday time since epoch
        fprintf(stderr, "%s: The cat hasn't been born yet.\n", PROGRAM_NAME);
        return false;
    }
    return true;
}//End of isBirthdayValid
----------------------------------------------------------------------------------------------------------------------*/